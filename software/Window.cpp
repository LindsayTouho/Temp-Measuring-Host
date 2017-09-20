#include"Window.h"

Window::Window()
{
	this->resize(700,400);
    	this->setObjectName(tr("this"));
	this -> setWindowTitle("SofeWare");


    	for(int i=0;i!=8;++i)
	{
        	Node[i]=new QLabel(this);                                    //label for show temperature use numbers
        	Node[i]->setText("<h3><font color=red>None</font></h3>");
	}

	Terminal=new QComboBox(this);                                      //every terminal contain 8 nodes
  	Terminal->addItem("None");
	nodeBox=new QComboBox(this);
	for(int i=0;i!=8;++i)
	{
		nodeBox->addItem(tr("Node")+QString::number(i+1));        //all nodes set as "Node" first
	}


	Open_Close=new QPushButton(this);                                //add buttons
	Open_Close->setText(tr("&Open"));
	Quit=new QPushButton(this);
	Quit->setText(tr("&Quit"));



	layout2=new QVBoxLayout;
	for(int i=0;i!=4;++i)                                            //arrange label for temperature
	{
		layout1[i]=new QHBoxLayout;
		layout1[i]->addWidget(Node[2*i]);
		layout1[i]->addWidget(Node[2*i+1]);
		layout2->addLayout(layout1[i]);
	}

	serial=new QSerialPort;



	line=new QLineSeries;                                          //prepare for chart
	line->setPen(QPen(Qt::blue,2,Qt::SolidLine));

	chart=new QChart;
	chart->setTitle(tr("Temperature"));
	chart->legend()->setAlignment(Qt::AlignBottom);
	chart->createDefaultAxes();

	axisX=new QValueAxis;

	axisX->setRange(-60,0);
  	axisX->setLabelFormat("%.2f");
  	axisX->setGridLineVisible(true);
  	axisX->setTickCount(6);
  	axisX->setMinorTickCount(4);
	axisX->setTitleText("Time/mintus");


  	chart->setAnimationOptions(QChart::SeriesAnimations);
  	chart->setAxisX(axisX,line);
  	view=new QChartView(this);
  	view->setChart(chart);
  	view->setRenderHint(QPainter::Antialiasing);

	localNum = 100;



	layout3= new QHBoxLayout;
	layout3->addLayout(layout2);
	layout3->addWidget(view);
	layout3->setStretchFactor(layout2,1);
	layout3->setStretchFactor(view,4);

	layout4=new QHBoxLayout;
	layout4->addWidget(Terminal);
	layout4->addWidget(nodeBox);
	layout4->addStretch();
	layout4->addWidget(Open_Close);
	layout4->addWidget(Quit);
	mainLayout=new QVBoxLayout;
	mainLayout->addLayout(layout3);
	mainLayout->addLayout(layout4);
	mainWidget=new QWidget;
	mainWidget->setLayout(mainLayout);
	this->setCentralWidget(mainWidget);



	connect(Open_Close,SIGNAL(clicked()),this,SLOT(on_Open_Close_clicked()));
	connect(Terminal,SIGNAL(currentTextChanged(QString)),this,SLOT(refresh()));
	connect(nodeBox,SIGNAL(currentTextChanged(QString)),this,SLOT(refresh()));
	connect(Quit,SIGNAL(clicked()),this,SLOT(close()));

	creatMenu();
	readSettings();
	//readSettings
};
Window::~Window()                       //need addition
{
	for(int i=0;i!=4;++i)
	{
		delete layout1[i];
	}
	delete layout2;
	delete Terminal;
	delete nodeBox;
	delete Open_Close;
	delete Quit;
	delete serial;
}
void Window::showSetting()
{
	if(!subWindow2)                                  //要死了，忘了cpp未初始化的指针不为空，会蠢死去：w
	{
		subWindow2 = new SettingWindow(this,&setting);
	}
	subWindow2 -> show();
	subWindow2 -> raise();
	subWindow2 -> activateWindow();

}
void Window::showSend()
{
	if(!subWindow1)
	{
		subWindow1 = new SendWindow(this);
		connect(subWindow1,SIGNAL(sendding(unsigned)),this,SLOT(serialSend(unsigned)));
	}
	subWindow1 -> show ();
	subWindow1 -> raise();
	subWindow1 -> activateWindow();
}

bool Window::addInValue(QDataStream& stream)                //temp add in data if it is useful
{
  	Data *temp=new Data(stream);
	if(temp->isCompleted())
	{
		data[temp->Id()].append(temp);
		QString tableName=(QString::number(temp->Id(),16).right(4).toUpper());
		QSqlQuery query;
		QString table = QString("CREATE TABLE IF NOT EXISTS");
		table += tableName;
		table += QString("(time timestamp NOT NULL default CURRENT_TIMESTAMP,T1   int       NULL,T2   int       NULL,T3   int       NULL,T4   int       NULL,T5   int       NULL,T6   int       NULL,T7   int       NULL,T8   int       NULL,PRIMARY KEY(time))ENGINE=InnoDB");
		query.exec(table);
		QString insert = QString("INSERT INTO") ;
		insert += tableName ;
		insert += QString("(T1,T2,T3,T4,T5,T6,T7,T8) VALUES(");
		for(int i=0;i!=8;++i){
			if(temp->isOpen(i))
				insert += QString::number(temp -> Temper(i));
			else
				insert += QString("NULL");
		query.exec(insert);
		}
		return true;

	}
	return false;
}
void Window::refresh()
{
	auto keys=data.keys();
    	for(qint16 i:keys)                                                   //refresh terminal box
    	{
       		if(Terminal->findText(QString::number(i,16).right(4).toUpper())==-1)
            	Terminal->addItem(QString::number(i,16).right(4).toUpper());
	}
	bool ok;
    	qint16 temp=Terminal->currentText().toInt(&ok,16);                           //temp is current  showed Terminal ID
    	if(!ok)
    	{
        	return;
    	}
    	auto lastData=data[temp].end()-1;
    	for(int i=0;i!=8;++i)                                                       //set label for show current temperature
    	{
        	if((*lastData)->isOpen(i))
        	{
            		Node[i]->setText(tr("<h3><font color=green>")+QString::number((*lastData)->Temper(i))+tr("°C</font></h3>"));
        	}
        	else
        	{
            		Node[i]->setText("<h3><font color=red>None</font></h3>");
        	}
    	}
	line->clear();                                            //refresh chart
    	chart->removeSeries(line);
    	chart->removeAxis(axisX);
	float x=0.0;
    	float y=0;
    	int i=0;
	y=nodeBox->currentIndex();
	while(x<=(setting . value("chartRange") .toInt()))						//添加设置后需要更改
	{
		if((lastData-i)==data[temp].begin())
				break;
		if(setting .value("timeUnit") .toString() == "second(s)")
			x=(*(lastData-i))->time().secsTo(QTime::currentTime());

		if(setting .value("timeUnit") .toString() == "minute(s)")
			x=(float)(*(lastData-i)) -> time().secsTo(QTime::currentTime())/60;

		if(setting .value("timeUnit") .toString() == "hour(s)")
			x=(float)(*(lastData-i)) -> time().secsTo(QTime::currentTime())/3600;
		line->append(-x,(*(lastData-i))->Temper(y));
		++i;
	}
    	chart->addSeries(line);
    	chart->createDefaultAxes();
    	chart->setAxisX(axisX,line);

 	//清除过多的本地数据
	for(auto temp:data)
	{
		if (temp.size()>=localNum)
		{
			for(auto i = temp.begin()+localNum;i != temp.end();++i)
			{
				delete *i;
			}
			temp.erase(temp.begin()+localNum,temp.end());
		}
	}
}

void Window::creatMenu()
{
	auto menu = this->menuBar();
	sendAction = new QAction(tr("Send"),this);
	connect(sendAction,SIGNAL(triggered()),this,SLOT(showSend()));
	settingAction = new QAction(tr("Setting"),this);
	connect(settingAction,SIGNAL(triggered()),this,SLOT(showSetting()));
	menu -> addAction(sendAction);
	menu -> addAction(settingAction);
}

bool Window::readSettings()
{
	if(setting. value("chartRange") !=QVariant())
	{
		axisX -> setRange(-(setting . value("chartRange").toInt()),0);

		axisX -> setTitleText(QString("Time/")+(setting . value("timeUnit").toString()));
		localNum = setting . value("dataNum").toInt();
		return true;
	}
	return false;
}



void Window::sleep(unsigned ms)
{
	QTime reachTime=QTime::currentTime().addMSecs(ms);
	while(QTime::currentTime() < reachTime)
	QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
void Window::on_Open_Close_clicked()
{
	if(serial==nullptr||!(serial->isOpen()))
	{
		const auto infos=QSerialPortInfo::availablePorts();
		if(infos.count()==0)
		{
			QMessageBox::warning(this,"Warning","No serial port is connecting",QMessageBox::Ok);
		    	return ;
		}
		if(infos.count()!=1)
			serial -> setPort(infos[(setting . value("serialName") . toInt())]);
		else
			serial->setPort(infos[0]);
		serial->setBaudRate(QSerialPort::Baud38400);
		serial->setParity(QSerialPort::NoParity);
		serial->setDataBits(QSerialPort::Data8);
		serial->setStopBits(QSerialPort::OneStop);
		if(serial->open(QIODevice::ReadWrite) && dbconnect())
		{
			serial->setDataTerminalReady(true);
			connect(serial,SIGNAL(readyRead()),this,SLOT(on_serial_readyRead()));
			Open_Close->setText(tr("&Close"));
		}
	}
	else
	{
		serial->close();
		Open_Close->setText(tr("&Open"));
	}
}
void Window::on_serial_readyRead()
{
	QByteArray b;
	b=serial->readAll();
	if(Buffer == nullptr)
		Buffer = new QByteArray(b);
	else
		Buffer-> append(b);
	b=*Buffer;
	QDataStream *temp = new QDataStream(b);
	addInValue(*temp);
	if(b != *Buffer)
	{
		*Buffer = b;
	}
	refresh();
}
void Window::serialSend(unsigned m)
{
	QByteArray byte;
	byte.resize(sizeof(unsigned));
	memcpy(byte.data(),&m,sizeof(m));
	serial ->write(byte);
}

bool Window::dbconnect(){
	if(setting.value("hostName") != QVariant())
	{
		db.setHostName(setting.value("hostName").toString());
		db.setDatabaseName(setting.value("databaseName").toString());
		db.setUserName(setting.value("userName").toString());
		db.setPassword(setting.value("passWord").toString());
		if(!db.open()){
			QMessageBox::critical(0,tr("Database Error"),db.lastError().text());
			return false;
		}
		return true;
	}
	else{
		db.setHostName("47.93.191.3");
		db.setDatabaseName("temperature");
		db.setUserName("public");
		db.setPassword("123456");
		if(!db.open()){
			QMessageBox::critical(0,tr("Database Error"),db.lastError().text());
			return false;
		}
		return true;
	}
}