#include"settingWindow.h"

settingWindow::settingWindow(QWidget *parent) : QDialog(parent){
    createWindow();
    createLayout();
    connect(OK,SIGNAL(clicked()),this,SLOT(Change()));
    connect(Cancle,SIGNAL(clicked()),this,SLOT(reject()));
}

settingWindow::~settingWindow()
{
    delete layout1;
    delete chartRange;
    delete timeRange;
    delete layout2;
    delete dataNum;
    delete numSlider;
    delete layout3;
    delete serialPort;
    delete layout5;
    delete OK;
    delete Cancle;
    delete mainLayout;
}

void settingWindow::createWindow(){
    resize(400,300);
    QSettings settings;

    this -> setWindowTitle(tr("设置"));
    chartRange = new QLabel(this);
    chartRange -> setText(tr("图表x轴范围(min)"));
    timeRange = new QSpinBox(this);
    timeRange->setRange(1,60);
    timeRange->setValue(settings.value("chart_range",QVariant(10)).toInt());

    dataNum = new QLabel (this);
    dataNum -> setText(tr("本地数据数量"));
    numSlider = new QSpinBox(this);
    numSlider -> setRange(2,10000);
    numSlider -> setValue(settings.value("ram_data_num",QVariant(100)).toInt());

    serialName = new QLabel(this);
    serialName -> setText(tr("串口"));
    serialPort = new QComboBox (this);
    const auto infos = QSerialPortInfo::availablePorts();
    for(auto i : infos)
    {
        serialPort->addItem(i.portName());
    }
    if(serialPort->findText(settings.value("serial_name",QVariant("COM1")).toString())!=-1)
        serialPort->setCurrentText(settings.value("serial_name",QVariant("COM1")).toString());

    temper = new QLabel(this);
    temper -> setText(tr("警报温度"));
    temperClarm = new QSpinBox;
    temperClarm -> setRange(0,0xFFFF);
    temperClarm-> setValue(settings.value("temper_clarm",QVariant(50)).toInt());

    humi = new QLabel(this);
    humi -> setText(tr("警报湿度"));
    humiClarm = new QSpinBox;
    humiClarm -> setRange(0,0xFFFF);
    humiClarm-> setValue(settings.value("humi_clarm",QVariant(50)).toInt());

    beam = new QLabel(this);
    beam -> setText(tr("警报光照"));
    beamClarm = new QSpinBox;
    beamClarm -> setRange(0,0xFF);
    beamClarm-> setValue(settings.value("beam_clarm",QVariant(10)).toInt());

    smog = new QLabel(this);
    smog -> setText(tr("警报气体浓度"));
    smogClarm = new QSpinBox;
    smogClarm -> setRange(0,0xFF);
    smogClarm-> setValue(settings.value("smog_clarm",QVariant(10)).toInt());

    OK = new QPushButton(this);
    Cancle = new QPushButton(this);
    OK -> setText(tr("确定"));
    Cancle -> setText(tr("取消"));

}

void settingWindow::createLayout(){
    layout1 = new QHBoxLayout;
    layout1 -> addWidget(chartRange);
    layout1 -> addWidget(timeRange);

    layout2 = new QHBoxLayout;
    layout2 -> addWidget(dataNum);
    layout2 -> addWidget(numSlider);

    layout3 = new QHBoxLayout;
    layout3 -> addWidget(serialName);
    layout3 -> addWidget(serialPort);

    layout6 = new QHBoxLayout;
    layout6->addWidget(temper);
    layout6->addWidget(temperClarm);

    layout7 = new QHBoxLayout;
    layout7->addWidget(humi);
    layout7->addWidget(humiClarm);

    layout8 = new QHBoxLayout;
    layout8->addWidget(beam);
    layout8->addWidget(beamClarm);

    layout9 = new QHBoxLayout;
    layout9->addWidget(smog);
    layout9->addWidget(smogClarm);

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
    mainLayout -> addLayout(layout6);
    mainLayout -> addStretch();
    mainLayout -> addLayout(layout7);
    mainLayout -> addStretch();
    mainLayout -> addLayout(layout8);
    mainLayout -> addStretch();
    mainLayout -> addLayout(layout9);
    mainLayout -> addStretch();
    mainLayout -> addLayout(layout5);
    mainLayout -> setSpacing(20);

    this -> setLayout(mainLayout);

}

void settingWindow::Change(){
    QSettings setting;
    setting.setValue("chart_range",timeRange -> value());
    setting.setValue("ram_data_num",numSlider->value());
    setting.setValue("serial_name",serialPort->currentText());
    setting.setValue("temper_clarm",temperClarm->value());
    setting.setValue("humi_clarm",humiClarm->value());
    setting.setValue("beam_clarm",beamClarm->value());
    setting.setValue("smog_clarm",smogClarm->value());
    emit this-> accept();
    this->close();
}
