#include"SendWindow.h"

SendWindow::SendWindow(QWidget *parent) : QDialog(parent)
{
	mainLayout = new QVBoxLayout;
	for(int i = 0 ; i<4 ; ++i)
	{
		lable[i] = new QLabel;
		button[i] = new QPushButton;
		button[i] -> setText("Send");
		layout[i] = new QHBoxLayout;
		layout[i] -> addWidget(lable[i]);
		layout[i] -> addWidget(button[i]);
		mainLayout -> addLayout(layout[i]);
	}
	lable[0] -> setText("Shake Hand");
	lable[1] -> setText("Gateway");
	lable[2] -> setText("Close Alarm");
	lable[3] -> setText("Manual Alarm");
	close = new QPushButton;
	close -> setText("Close");
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
