#include"sender.h"
#include<QDebug>

Sender::Sender(QWidget *parent) : QDialog(parent){
    resize(300,600);
    this-> setWindowTitle(tr("发送"));
    mainLayout = new QVBoxLayout;
    for(int i = 0 ; i<12 ; ++i)
    {
        lable[i] = new QLabel;
        button[i] = new QPushButton;
        button[i] -> setText(tr("发送"));
        layout[i] = new QHBoxLayout;
        layout[i] -> addWidget(lable[i]);
        layout[i] -> addWidget(button[i]);
        mainLayout -> addLayout(layout[i]);
    }
    lable[ 0] -> setText(tr("握手"));
    lable[ 1] -> setText(tr("网关"));
    lable[ 2] -> setText(tr("取消警报"));
    lable[ 3] -> setText(tr("手动警报"));
    lable[ 4] -> setText(tr("解除网关"));
    lable[ 5] -> setText(tr("上传"));
    lable[ 6] -> setText(tr("灯测试暗"));
    lable[ 7] -> setText(tr("灯测试亮"));
    lable[ 8] -> setText(tr("水泵关"));
    lable[ 9] -> setText(tr("水泵开"));
    lable[10] -> setText(tr("风扇关"));
    lable[11] -> setText(tr("风扇开"));
    close = new QPushButton;
    close -> setText(tr("关闭"));
    mainLayout-> addWidget(close);
    connect(button[0],SIGNAL(clicked(bool)),this,SLOT(buttonEmit0()));
    connect(button[1],SIGNAL(clicked(bool)),this,SLOT(buttonEmit1()));
    connect(button[2],SIGNAL(clicked(bool)),this,SLOT(buttonEmit2()));
    connect(button[3],SIGNAL(clicked(bool)),this,SLOT(buttonEmit3()));
    connect(button[4],SIGNAL(clicked(bool)),this,SLOT(buttonEmit4()));
    connect(button[5],SIGNAL(clicked(bool)),this,SLOT(buttonEmit5()));
    connect(button[6],SIGNAL(clicked(bool)),this,SLOT(buttonEmit6()));
    connect(button[7],SIGNAL(clicked(bool)),this,SLOT(buttonEmit7()));
    connect(button[8],SIGNAL(clicked(bool)),this,SLOT(buttonEmit8()));
    connect(button[9],SIGNAL(clicked(bool)),this,SLOT(buttonEmit9()));
    connect(button[10],SIGNAL(clicked(bool)),this,SLOT(buttonEmit10()));
    connect(button[11],SIGNAL(clicked(bool)),this,SLOT(buttonEmit11()));

    connect(close,SIGNAL(clicked(bool)),this,SLOT(close()));
    setLayout(mainLayout);
}

Sender::~Sender(){
    for(int i = 0 ;i<12 ; ++i)
    {
        delete lable[i];
        delete button[i];
        delete layout[i];
    }
    delete mainLayout;
}

