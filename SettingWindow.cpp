#include"SettingWindow.h"

SettingWidow::SettingWindow(QDialog *parent) : QDialog(parent)
{
	chartRange = new QLabel(this);
	chartRange -> setText("Chart Range");
	timeRange = new QSpinBox(this);
	timeRange->setRange(1,60);
	timeUnit = new QComboBox(this);
	timeUnit->addItem("minute(s)");
	timeUnit->addItem("hour(s)");
	
	dataNum = new QLabel (this);
	dataNum -> setText("Lacol Data Number")
	numSlider = new QSlider(this);
	numSlider -> setRage(1,1000);

	serialName = new QLabel(this);
	serialName -> setText("Serial Port");
	serialPort = new QComboBox (this);
	const auto infos = QSerialPortInfo:availablePorts();
	for(auto i : infos)
	{
		serialPort->addItem(i.portName().toStdString);
	}

	database     = new QLabel(this);
	database     ->setText("Database");
	hostname     = new QLineEdit(this);
	username     = new QLineEdit(this);
	passwd       = new QLineEdit(this);
	databasename = new QLineEdit(this);

	OK = new QPushButton(this);
	Cancle = new QPushButton(this);
	OK -> setText("OK");
	Cancle -> setText("Cancle");

	layout1 = new QHBoxLayout;
	layout1 -> addWidget(chartRange);
	layout1 -> addWidget(timeRange);
	layout1 -> addWidget(timeUnit);

	layout2 = new QHBoxlayout;
	layout2 -> addWidget(dataNum);
	layout2 -> addWidget(numSlider);

	layout3 = new QHBoxLayout;
	layout3 -> addWidget(serialName);
	layout3 -> addWidget(serialPort);

	layout4 = new QVBoxLayout;
	layout4 -> addWidget(database);
	layout4 -> addWidget(hostname);
	layout4 -> addWidget(usrname);
	layout4 -> addWidget(passwd);
	layout4 -> addWidget(databasename);

	layout5 = new QHBoxLayout;
	layout5 -> addWidget(OK);
	layout5 -> addWidget(Cancle);
	
	mainLayout = new QVBoxLayout;
	mainLayout -> addLayout(layout1);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout2);
	mainLayout -> addStretch();
	mainlayout -> addLayout(layout3);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout4);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout5);

	this -> setCentralLayout(mainLayout);

	connect(OK,SIGNAL(clicked()),this,SOLT(Change()));
	connect(Cancle,SIGNAL(clicked()),this,SOLT(close()));
}

SettingWindow::~SettingWindow()
{
	delete layout1;
	delete chartRange;
	delete timeRange;
	delete timeUnit;
	delete layout2;
	delete dataNum;
	delete numSlider;
	delete layout3;
	delete serialPort;
	delete layout4;
	delete database;
	delete hostname;
	delete username;
	delete passwd;
	delete databasename;
	delete layout5;
	delete OK;
	delete Cancle;
	delete mainlayout;
}

void SettingWindow::Change()
{
	emit settingChanged();
	
