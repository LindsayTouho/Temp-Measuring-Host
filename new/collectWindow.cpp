#include"collectWindow.h"
#include<QDebug>

mainWindow::mainWindow(){
    resize(1000,1000);
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
    menu -> addAction(settingAction);
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
    settingWidget-> show();
    settingWidget -> raise();
    settingWidget -> activateWindow();
}

void mainWindow::insertToDb(Data *n){
    QSqlQuery query;
    query.exec(tr("INSERT INTO data(name,timer,temperature,humili"))
}
