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
    createEvent();
    createMenu();
    readSetting();
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
}

void mainWindow::createLayout(){
    right = new QSplitter(Qt::Vertical);
    right -> addWidget(chart);
    right -> addWidget(sql);

    center = new QSplitter(Qt::Horizontal);
    center -> addWidget(tree);
    center -> addWidget(right);
    center -> setStretchFactor(1,1);
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

void mainWindow::refresh(Data *n){

}

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
    connect(S,SIGNAL(readed(Data*)),tree,SLOT(append(Data*)));
    connect(S,SIGNAL(readed(Data*)),sql,SLOT(refresh()));
}

mainWindow::~mainWindow(){

}

void mainWindow::changeTable(QTreeWidgetItem *item, int cloum){
    if(item->childCount()==4){
        sql->changeTerminal(item->text(cloum));
    }
}

void mainWindow::changeChart(QTreeWidgetItem *item, int cloum){
    if(item->childCount()==0){
        treeWidgetItem * treeItem = (treeWidgetItem *)item;
        chart->setline(treeItem->data());
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

/*void mainWindow::insertToDb(Data *n){
   QSqlQuery query;
   query.exec(tr("INSERT INTO data(name,timer,temperature,humidity,beam,smog) "
                 "values(\'%1\',\'%2\',%3,%4,%5,%6)")
              .arg(n->terminal_name())
              .arg(n->time().toString("yyyy-MM-dd hh:mm:ss"))
              .arg(QString::number(n->temperature()))
              .arg(QString::number(n->humidity()))
              .arg(QString::number(n->beam()))
              .arg(QString::number(n->smog()))
              );
}*/

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
