#include"sendWindow.h"

SendWindow::SendWindow(QWidget *parent) : QDialog(parent)
{
	this -> setWindowTitle("Send");
	mainLayout = new QVBoxLayout;
	for(int i = 0 ; i<4 ; ++i)
	{
		lable[i] = new QLabel;
		button[i] = new QPushButton;
		button[i] -> setText(tr("发送"));
		layout[i] = new QHBoxLayout;
		layout[i] -> addWidget(lable[i]);
		layout[i] -> addWidget(button[i]);
		mainLayout -> addLayout(layout[i]);
	}
	lable[0] -> setText(tr("握手"));
	lable[1] -> setText(tr("网关"));
	lable[2] -> setText(tr("取消警报"));
	lable[3] -> setText(tr("手动警报"));
	close = new QPushButton;
	close -> setText(tr("关闭"));
	mainLayout-> addWidget(close);
	connect(button[0],SIGNAL(clicked()),this,SLOT(button1()));
	connect(button[1],SIGNAL(clicked()),this,SLOT(button2()));
	connect(button[2],SIGNAL(clicked()),this,SLOT(button3()));
	connect(button[3],SIGNAL(clicked()),this,SLOT(button4()));
	connect(close,SIGNAL(clicked()),this,SLOT(accept()));
	setLayout(mainLayout);
}
SendWindow::~SendWindow()
{
	for(int i = 0 ;i<4 ; ++i)
	{
		delete lable[i];
		delete button[i];
		delete layout[i];
	}
	delete mainLayout;
}
