#include"mainWindow.h"
#include<iostream>
using namespace std;

Window::Window(){

    createMainWindow();
    setBuJu();
    createEvent();
    createMenu();

    localNum = setting . value("dataNum",QVariant(100)).toInt();
    serial=new QSerialPort;
}

Window::~Window()
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


void Window::createMainWindow(){
    this->resize(700,400);
    this->setObjectName(tr("this"));
    this -> setWindowTitle("SofeWare");


    for(int i=0;i!=8;++i)
	{
        	Node[i]=new QLabel(this);
        	Node[i]->setText("<h3><font color=red>None</font></h3>");
	}

	Terminal=new QComboBox(this);
  	Terminal->addItem("空");

	nodeBox=new QComboBox(this);
	for(int i=0;i!=8;++i)
	{
		nodeBox->addItem(tr("节点")+QString::number(i+1));
	}


	Open_Close=new QPushButton(this);
	Open_Close->setText(tr("开启"));
	Quit=new QPushButton(this);
	Quit->setText(tr("退出"));






	line=new QLineSeries;
	line->setPen(QPen(Qt::blue,2,Qt::SolidLine));

	chart=new QChart;
	chart->setTitle(tr("温度"));
	chart->legend()->setAlignment(Qt::AlignBottom);
	chart->createDefaultAxes();

	axisX=new QValueAxis;

	axisX -> setRange(-(setting . value("chartRange",QVariant(60)).toInt()),0);
  	axisX->setLabelFormat("%.2f");
  	axisX->setGridLineVisible(true);
  	axisX->setTickCount(6);
  	axisX->setMinorTickCount(4);
	axisX -> setTitleText(QString("Time/")+(setting . value("timeUnit",QVariant("Minute(s)")).toString()));


  	chart->setAnimationOptions(QChart::SeriesAnimations);
  	chart->setAxisX(axisX,line);
  	view=new QChartView(this);
  	view->setChart(chart);
  	view->setRenderHint(QPainter::Antialiasing);


}

void Window::setBuJu(){
    layout2=new QVBoxLayout;                //左侧数字部分
    for(int i=0;i!=4;++i)
    {
        layout1[i]=new QHBoxLayout;
        layout1[i]->addWidget(Node[2*i]);
        layout1[i]->addWidget(Node[2*i+1]);
        layout2->addLayout(layout1[i]);
    }



    layout3= new QHBoxLayout;               //layout2 + 右侧折线图部分
	layout3->addLayout(layout2);
	layout3->addWidget(view);
	layout3->setStretchFactor(layout2,1);
	layout3->setStretchFactor(view,4);

	layout4=new QHBoxLayout;               //下侧控制部分
	layout4->addWidget(Terminal);
	layout4->addWidget(nodeBox);
	layout4->addStretch();
	layout4->addWidget(Open_Close);
	layout4->addWidget(Quit);


	mainLayout=new QVBoxLayout;            //主布局  显示部分 和 控制部分结合
	mainLayout->addLayout(layout3);
	mainLayout->addLayout(layout4);
	mainWidget=new QWidget;
	mainWidget->setLayout(mainLayout);
	this->setCentralWidget(mainWidget);
}

void Window::createMenu()
{
	auto menu = this->menuBar();

	sendAction = new QAction(tr("传输协议"),this);
	connect(sendAction,SIGNAL(triggered()),this,SLOT(showSend()));

	settingAction = new QAction(tr("设置"),this);
	connect(settingAction,SIGNAL(triggered()),this,SLOT(showSetting()));

    debugAction = new QAction(tr("详细信息"),this);
	connect(debugAction,SIGNAL(triggered()),this,SLOT(showDebug()));

	menu -> addAction(sendAction);
	menu -> addAction(settingAction);
    menu -> addAction(debugAction);
}

void Window::createEvent(){
    connect(Open_Close,SIGNAL(clicked()),this,SLOT(on_Open_Close_clicked()));
    connect(Terminal,SIGNAL(currentTextChanged(QString)),this,SLOT(refresh()));
    connect(nodeBox,SIGNAL(currentTextChanged(QString)),this,SLOT(refresh()));
    connect(Quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(this,SIGNAL(closewindow()),this,SLOT(close()));
}

void Window::sleep(unsigned ms)
{
	QTime reachTime=QTime::currentTime().addMSecs(ms);
	while(QTime::currentTime() < reachTime)
	QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

// QString convert(char * chs){
//     QString result;
//     char ch = chs;
//     while(*ch != '\0'){
//         if(*ch <10)
//             result.append('0'+ *ch);
//         else
//             result.append(*ch -10 + 'A');
//     }
//     result.append('\n');
//     return result;
// }

void Window::on_serial_readyRead()
{

    cout<<1<<endl;
	QByteArray b;
	b=serial->readAll();
    // bool ok;
    // debugWindow -> showMessage(convert(byte_head.data()))

	if(Buffer == nullptr)
		Buffer = new QByteArray(b);
	else
		Buffer-> append(b);
	b=*Buffer;
	QDataStream *temp = new QDataStream(b);
    if(	addInValue(*temp))
	{
		*Buffer = b;
	}
	refresh();
}



void Window::on_Open_Close_clicked()
{
	if(serial==nullptr||!(serial->isOpen()))
	{
		const auto infos=QSerialPortInfo::availablePorts();
		if(infos.count()==0)
		{
            throwEvent("没有串口连接到本设备");
		    return ;
		}
		serial -> setPort(infos[(setting . value("serialName",QVariant(0)) . toInt())]);
		serial->setBaudRate(QSerialPort::Baud38400);
		serial->setParity(QSerialPort::NoParity);
		serial->setDataBits(QSerialPort::Data8);
		serial->setStopBits(QSerialPort::OneStop);
        if(!serial->open(QIODevice::ReadWrite)){
            throwEvent("串口未能打开");
            return;
        }
        if (!dbconnect()){
            throwEvent("数据库连接失败");
            return;
        }

        serial->setDataTerminalReady(true);
        connect(serial,SIGNAL(readyRead()),this,SLOT(on_serial_readyRead()));
        Open_Close->setText(tr("关闭"));
	}
	else
	{
		serial->close();
		Open_Close->setText(tr("开启"));
	}
}

void Window::throwEvent(QString m){
    int a=QMessageBox::warning(this,tr("Warning"),m,QMessageBox::Ok | QMessageBox::Close);
    if(a==QMessageBox::Close)
    {
        emit closewindow();
    }
}

bool Window::dbconnect(){
    db.setHostName(setting.value("hostName",QVariant("47.93.191.3")).toString());
    db.setDatabaseName(setting.value("databaseName",QVariant("temperature")).toString());
    db.setUserName(setting.value("userName",QVariant("public")).toString());
    db.setPassword(setting.value("passWord",QVariant("123456")).toString());
    if(!db.open()){
        return false;
    }
    return true;
}

void Window::serialSend(unsigned m) //用于传递网关之类的协议
{
	QByteArray byte;
	byte.resize(sizeof(unsigned));
	memcpy(byte.data(),&m,sizeof(m));
	serial -> write(byte);
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

void Window::showSetting()
{
	if(!subWindow2)                                  //要死了，忘了cpp未初始化的指针不为空，会蠢死去
	{
		subWindow2 = new SettingWindow(this,&setting);
	}
	subWindow2 -> show();
	subWindow2 -> raise();
	subWindow2 -> activateWindow();

}

void Window::showDebug(){

    if(!subWindow3)                                  //要死了，忘了cpp未初始化的指针不为空，会蠢死去
    {
        subWindow3 = new debugWindow(this);
    }

    subWindow3 -> show();
    subWindow3 -> raise();
    subWindow3 -> activateWindow();
}

void Window::refresh()
{
	auto keys=data.keys();
    for(qint16 i:keys)
    {
       	if(Terminal->findText(QString::number(i,16).right(4).toUpper())==-1)
        Terminal->addItem(QString::number(i,16).right(4).toUpper());
	}
	bool ok;
    qint16 temp=Terminal->currentText().toInt(&ok,16);
	if(!ok)
    {
    	return;
	}
	auto lastData=data[temp].end()-1;
    for(int i=0;i!=8;++i)
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
	line->clear();
    chart->removeSeries(line);
    chart->removeAxis(axisX);
	float x=0.0;
    float y=0;
    int i=0;
	y=nodeBox->currentIndex();
    if((*lastData) -> isOpen(y)){
        while(x<=(setting . value("chartRange",QVariant(60)) .toInt()))						//添加设置后需要更改
        {
            if((lastData-i)==data[temp].begin())
            break;
            if(setting .value("timeUnit",QVariant("minute(s)")) .toString() == "second(s)")
                x=(*(lastData-i))->time().secsTo(QTime::currentTime());
            if(setting .value("timeUnit",QVariant("minute(s)")) .toString() == "minute(s)")
			    x=(float)(*(lastData-i)) -> time().secsTo(QTime::currentTime())/60;

		    if(setting .value("timeUnit",QVariant("minute(s)")) .toString() == "hour(s)")
			   x=(float)(*(lastData-i)) -> time().secsTo(QTime::currentTime())/3600;

            line->append(-x,(*(lastData-i))->Temper(y));
            ++i;
	   }
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

bool Window::addInValue(QDataStream& stream)
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
