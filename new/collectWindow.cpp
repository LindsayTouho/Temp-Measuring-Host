#include"collectWindow.h"
#include<QDebug>

mainWindow::mainWindow(){
    resize(1200,1000);
    move(350,0);
    QCoreApplication::setOrganizationName("CSL");
    QCoreApplication::setApplicationName("Mysoft");
    dbconnect();
    createWidget();
    createLayout();
    createMenu();
    readSetting();
    createEvent();
}

bool mainWindow::dbconnect(){
    db.setDatabaseName("data.db");
    if(db.open())
        return true;
    return false;
}

void mainWindow::createWidget(){
    tree = new treeWidget(this);
    chart = new chartWidget(this);
    sql = new sqlWidget(this,"",db);
    openCloseButton = new QPushButton(this);
    openCloseButton->setText(tr("&Open"));
    quitButton = new QPushButton(this);
    quitButton -> setText(tr("&Quit"));
    clarmWidget = new QTextEdit;
    clarmWidget -> setReadOnly(true);

}

void mainWindow::createLayout(){
    right = new QSplitter(Qt::Vertical);
    right -> addWidget(chart);
    right -> addWidget(sql);

    center = new QSplitter(Qt::Horizontal);
    center -> addWidget(tree);
    center -> addWidget(right);
    center -> setStretchFactor(1,1);
    center -> addWidget(clarmWidget);
    buttom = new QHBoxLayout;
    buttom -> addWidget(openCloseButton);
    buttom -> addWidget(quitButton);
    mainLayout = new QVBoxLayout;
    mainLayout ->addWidget(center);
    mainLayout -> addLayout(buttom);
    mainWidget = new QWidget;
    mainWidget -> setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

void mainWindow::createEvent(){
    connect(openCloseButton,SIGNAL(clicked()),this,SLOT(open_close()));
    connect(tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(changeTable(QTreeWidgetItem*,int)));
    connect(tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(changeChart(QTreeWidgetItem*,int)));
    connect(quitButton,SIGNAL(clicked(bool)),this,SLOT(close()));

}

void mainWindow::createMenu(){
    auto menu = menuBar();
    settingAction = new QAction(tr("设置"),this);
    connect(settingAction,SIGNAL(triggered(bool)),this,SLOT(showSetting()));
    senderAction = new QAction(tr("发送"),this);
    connect(senderAction,SIGNAL(triggered(bool)),this,SLOT(showSender()));
    debugerAction = new QAction(tr("调试"),this);
    connect(debugerAction,SIGNAL(triggered(bool)),this,SLOT(showDebuger()));
    menu -> addAction(senderAction);
    menu -> addAction(settingAction);
    menu -> addAction(debugerAction);
}

/*void mainWindow::refresh(Data *n){

}*/

void mainWindow::open_close(){
    if(openCloseButton->text()==tr("&Open")){
        if(S->open(true))
            openCloseButton->setText(tr("&Close"));
    }
    else{
        if(!(S->open(false)))
            openCloseButton->setText(tr("&Open"));
    }

}

void mainWindow::readSetting(){
    QSettings settings;
    chart->setRange(-(settings.value("chart_range",QVariant(10)).toInt()),0);
    if(S)
        delete S;
    S = new serial(settings.value("serial_name",QVariant("COM!")).toString());
    connect(S,SIGNAL(readed(Data*)),this,SLOT(checkClarm(Data*)));
    S->open(QIODevice::ReadWrite);
    connect(S,SIGNAL(readed(Data*)),tree,SLOT(append(Data*)));
    connect(S,SIGNAL(readed(Data*)),sql,SLOT(refresh()));
}

mainWindow::~mainWindow(){

}

void mainWindow::changeTable(QTreeWidgetItem *item, int cloum){
    if(item->childCount()!=0){
        sql->changeTerminal(item->text(cloum));
    }
}

void mainWindow::changeChart(QTreeWidgetItem *item, int cloum){
    if(item->childCount()==0){
        void * temp = item->data(0,Qt::UserRole).value<void *>();
        chart->setline((QLineSeries *)temp);
        changeTable(item->parent(),cloum);
    }
}

void mainWindow::showSetting(){
    if(!settingWidget){
        settingWidget = new settingWindow(this);
    }
    connect(settingWidget,SIGNAL(accepted()),this,SLOT(readSetting()));
    settingWidget-> show();
    settingWidget -> raise();
    settingWidget -> activateWindow();
}


void mainWindow::showSender(){
    if(!senderWidget){
        senderWidget = new Sender(this);
    }
    connect(senderWidget,SIGNAL(sendding(uint)),this,SLOT(serialSend(uint)));
    senderWidget -> show();
    senderWidget -> raise();
    senderWidget -> activateWindow();
}

void mainWindow::serialSend(unsigned data){

    QByteArray byte;
    byte.resize(4);
    memcpy(byte.data(),&data,4);
    if(S->isOpen())
        S -> write(byte);
}

void mainWindow::showDebuger(){
    if(!debugeWidget){
        debugeWidget = new debugWindow;
    }
    connect(S,SIGNAL(originMessage(QByteArray)),debugeWidget,SLOT(showMessage(QByteArray)));
    debugeWidget -> show();
    debugeWidget -> raise();
    debugeWidget -> activateWindow();
}

void mainWindow::checkClarm(Data *n){
    QSettings setting;
    if(n->type()==0x0600){
        if(n->temperature() > setting.value("temper_clarm").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 温度过高：")+QString::number(n->temperature())+tr("\n"));
        }
        if(n->temperature() < setting.value("temper_clarm_down").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 温度过低：")+QString::number(n->temperature())+tr("\n"));
        }
        if(n->humidity() > setting.value("humi_clarm").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 湿度过高：")+QString::number(n->humidity())+tr("\n"));
        }
        if(n->humidity() < setting.value("humi_clarm_down").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 湿度过低：")+QString::number(n->humidity())+tr("\n"));
        }
        if(n->beam() > setting.value("beam_clarm").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 光照过高：")+QString::number(n->beam())+tr("\n"));
        }
        if(n->beam() < setting.value("beam_clarm_down").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 光照过低：")+QString::number(n->beam())+tr("\n"));
        }
        if(n->smog() > setting.value("smog_clarm").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr(" 气体浓度过高：")+QString::number(n->smog())+tr("\n"));
        }
        if(n->smog() < setting.value("smog_clarm_down").toInt()){
            serialSend(0x002900FE);
            clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+
                               tr("烟雾浓度过低：")+QString::number(n->smog())+tr("\n"));
        }
    }
    else if(n->type()==0x0200){
        for(int i=0;i<8;i++){
            if(n->temper(i)!=0&&((n->temper(i)) > (setting.value("temper_clarm").toInt()))){
                clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+tr("-")+QString::number(i+1)+
                                   tr(" 温度过高：")+QString::number(n->temper(i))+tr("\n"));
                serialSend(0x002900FE);
            }
            if(n->temper(i)!=0&&n->temper(i)< setting.value("temper_clarm_down").toInt()){
                clarmWidget -> insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ")+n->terminal_name()+tr("-")+QString::number(i+1)+
                                   tr(" 温度过低：")+QString::number(n->temper(i))+tr("\n"));
                serialSend(0x002900FE);
            }
        }
    }
}
