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
    QSettings settings;

    this -> setWindowTitle("Settings");
    chartRange = new QLabel(this);
    chartRange -> setText(tr("图表x轴范围(min)"));
    timeRange = new QSpinBox(this);
    timeRange->setRange(1,60);
    timeRange->setValue(settings.value("chart_range",QVariant(10)).toInt());

    dataNum = new QLabel (this);
    dataNum -> setText(tr("本地数据数量"));
    numSlider = new QSpinBox(this);
    numSlider -> setRange(2,1000);
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
    mainLayout -> addLayout(layout5);
    mainLayout -> setSpacing(20);

    this -> setLayout(mainLayout);

}

void settingWindow::Change(){
    QSettings setting;
    setting.setValue("chart_range",timeRange -> value());
    setting.setValue("ram_data_num",numSlider->value());
    setting.setValue("serial_name",serialPort->currentText());
    this->close();
}
