#include"SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent,QSettings *oldSetting) : QDialog(parent)
{
	localSetting = oldSetting;
	this -> setWindowTitle("Settings");
	chartRange = new QLabel(this);
	chartRange -> setText("Chart Range");
	timeRange = new QSpinBox(this);
	timeRange->setRange(1,60);
	timeUnit = new QComboBox(this);
	timeUnit->addItem("second(s)");
	timeUnit->addItem("minute(s)");
	timeUnit->addItem("hour(s)");

	dataNum = new QLabel (this);
	dataNum -> setText("Lacol Data Number");
	numSlider = new QSpinBox(this);
	numSlider -> setRange(0,1000);
	numSlider -> setValue(100);

	serialName = new QLabel(this);
	serialName -> setText("Serial Port");
	serialPort = new QComboBox (this);
	const auto infos = QSerialPortInfo::availablePorts();
	for(auto i : infos)
	{
		serialPort->addItem(i.portName());
	}
	database     = new QLabel(this);
	database     ->setText("Database");
	host 	     = new QLabel(this);
	host	     -> setText("Hostname");
	hostname     = new QLineEdit(this);
	hostname     -> setText("47.93.191.3");
	user	     = new QLabel(this);
	user	     -> setText("Username");
	username     = new QLineEdit(this);
	username     -> setText("public");
	pass 	     = new QLabel(this);
	pass         -> setText("Password");
	passwd       = new QLineEdit(this);
	passwd       -> setText("123456");
	dataname     = new QLabel(this);
	dataname     -> setText("Database Name");
	databasename = new QLineEdit(this);
	databasename -> setText("temperature");


	OK = new QPushButton(this);
	Cancle = new QPushButton(this);
	OK -> setText("OK");
	Cancle -> setText("Cancle");

	layout1 = new QHBoxLayout;
	layout1 -> addWidget(chartRange);
	layout1 -> addWidget(timeRange);
	layout1 -> addWidget(timeUnit);

	layout2 = new QHBoxLayout;
	layout2 -> addWidget(dataNum);
	layout2 -> addWidget(numSlider);

	layout3 = new QHBoxLayout;
	layout3 -> addWidget(serialName);
	layout3 -> addWidget(serialPort);

	layout6 = new QHBoxLayout;
	layout6 ->addWidget(host);
	layout6 -> addWidget(hostname);

	layout7 = new QHBoxLayout;
	layout7 -> addWidget(user);
	layout7 -> addWidget(username);

	layout8 = new QHBoxLayout;
	layout8 -> addWidget(pass);
	layout8 -> addWidget(passwd);

	layout9 = new QHBoxLayout;
	layout9 -> addWidget(dataname);
	layout9 -> addWidget(databasename);


	layout4 = new QVBoxLayout;
	layout4 -> addWidget(database);
	layout4 -> addLayout(layout6);
	layout4 -> addLayout(layout7);
	layout4 -> addLayout(layout8);
	layout4 -> addLayout(layout9);

	layout5 = new QHBoxLayout;
	layout5 -> addWidget(OK);
	layout5 -> addWidget(Cancle);

	mainLayout = new QVBoxLayout;
	mainLayout -> addLayout(layout1);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout2);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout3);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout4);
	mainLayout -> addStretch();
	mainLayout -> addLayout(layout5);
	mainLayout -> setSpacing(20);
	layout4    -> setSpacing(10);

	this -> setLayout(mainLayout);

	connect(OK,SIGNAL(clicked()),this,SLOT(Change()));			//change也会崩溃
	connect(Cancle,SIGNAL(clicked()),this,SLOT(reject()));

	if(localSetting != nullptr && localSetting -> value("chartRange") != QVariant())                                            //这里有问题
	{
		timeRange -> setValue(localSetting -> value("chartRange").toInt());
		timeUnit ->  setCurrentText(localSetting -> value("timeUnit").toString());
		numSlider -> setValue(localSetting -> value("numSlider").toInt());
		serialPort -> setCurrentIndex(localSetting->value("serialName").toInt());
		hostname ->  setText(localSetting-> value("hostName").toString());
		username -> setText(localSetting -> value("userName").toString());
		passwd -> setText(localSetting -> value("passWord").toString());
		databasename -> setText(localSetting -> value("databaseName").toString());
	}
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
	delete mainLayout;
}

void SettingWindow::Change()
{
	localSetting -> setValue("chartRange",timeRange->value());                       //设置1：表格范围
	localSetting -> setValue("timeUnit",timeUnit -> currentText());                        //设置2：表格范围的单位
	localSetting -> setValue("dataNum",numSlider -> value());                        //设置3：本地保存数据个数
	localSetting -> setValue("serialName",serialPort -> currentIndex());		//设置4：串口名
	localSetting -> setValue("hostName",hostname -> text());  			//设置5:主机名
	localSetting -> setValue("userName",username -> text());                         //设置6：用户名
	localSetting -> setValue("passWord",passwd -> text()); 				//设置6:密码
	localSetting -> setValue("databaseName",databasename -> text());			//设置7:数据库名
	QMessageBox::warning(this,tr("Warning"),tr("Restart to take effect"),QMessageBox::Ok);
	this -> accept();
}