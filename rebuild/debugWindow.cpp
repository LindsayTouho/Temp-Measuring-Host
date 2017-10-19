#include"debugWindow.h"



debugWindow::debugWindow(QWidget *parent) : QDialog(parent){


    showWidget = new QTextEdit;
    clearButton = new QPushButton;
    buttomLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;
    quitButton = new QPushButton;

    showWidget -> setReadOnly(true);
    clearButton -> setText(tr("清空"));
    quitButton -> setText(tr("退出"));

    buttomLayout -> addWidget(clearButton);
    buttomLayout -> addWidget(quitButton);
    mainLayout -> addWidget(showWidget);
    mainLayout -> addLayout(buttomLayout);
    setLayout(mainLayout);



    connect(clearButton,SIGNAL(clicked()),showWidget,SLOT(clear()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
}

debugWindow::~debugWindow(){
    delete showWidget;
    delete clearButton;
    delete quitButton;
    delete buttomLayout;
    delete mainLayout;
}
void debugWindow::showMessage(QString *messages){
    showWidget->insertPlainText(*messages);
}
