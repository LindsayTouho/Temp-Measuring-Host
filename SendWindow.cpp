#include"SendWindow.h"

SendWindow::SendWindow(QDialog *parent) : QDialog(parent)
{
	mainLayout = new QVBoxLayout;
	for(int i = 0 ; i<4 ; ++i)
	{
		lable[i] = new QLabel;
		button[i] = new QPushButton;
		button[i] -> setText("Send");
		layout1[i] = new QHBoxLayout;
		layout1[i] -> addWidget(lable[i]);
		layout1[i] -> addWidget(button[i]);
		mainLayout -> addLayout(layout1[i]);
		connect(button[i],SIHNAL(clicked
	}
	lable[0] -> setText("Shake Hand");
	lable[1] -> setText("Gateway");
	lable[2] -> setText("Close Alarm");
	lable[3] -> setText("Manual Alarm");
	connect(button[1],SIGNAL(clicked()),this,SLOT(button1()));
	connect(button[2],SIGNAL(clicked()),this,SLOT(button2()));
	connect(button[3],SIGNAL(clicked()),this,SLOT(button3()));
	connect(button[4],SIGNAL(clicked()),this,SLOT(button4()));
}
SendWindow::~SendWindow()
{
	for(int i = 0 ;i<4 ; ++i)
	{
		delete lable[i];
		delete button[i];
		delete layout1[i];
	}
	delete mainLayout;
}
