#include"chartWidget.h"


chartWidget::chartWidget(QWidget *parent,int Item):QWidget(parent){
  resentValue = new QLabel;
  currentTime = new QLabel;

  currentItem = Item;


  line = new QLineSeries;     //设置折线图
  line -> setPen(QPen(Qt::blue,2,Qt::SolidLine));
  chart = new QChart;
  chart -> setMargins(QMargins(0,0,0,0));
  chart -> legend() -> hide();
  chart -> setPlotAreaBackgroundBrush(QBrush(Qt::black));
  chart -> setPlotAreaBackgroundVisible(true);
  chart -> createDefaultAxes();
  axisX = new QValueAxis;
  axisX -> setLabelFormat("%.1f");
  axisX -> setGridLineVisible(true);
  axisX -> setTickCount(6);
  axisX -> setMinorTickCount(4);
  axisX -> setRange(-60,0);
  axisX -> setTitleText(tr("XXX"));
  chart -> setAxisX(axisX,line);
  view = new QChartView(this);
  view -> setChart(chart);
  view -> setRenderHint(QPainter::Antialiasing);

  headLayout = new QHBoxLayout;
  headLayout -> addWidget(currentTime);
  headLayout -> addWidget(resentValue);

  mainLayout = new QVBoxLayout;
  mainLayout -> addLayout(headLayout);
  mainLayout -> addWidget(view);
  setLayout(mainLayout);
  refresh();
}

chartWidget::~chartWidget(){
  delete resentValue;
  delete currentTime;
  delete chart;
  delete axisX;
  delete line;
  delete view;
}

void chartWidget::push(Data &n){
  // chart -> removeSeries(line);
  // chart -> removeAxis(axisX);

  if(currentItem == 0){
    line -> append(-(n.time().secsTo(QTime::currentTime())),n.temperature());
    resentValue -> setText(QString::number(n.temperature()));
  }
  else if(currentItem == 1){
    line -> append(-(n.time().secsTo(QTime::currentTime())),n.humidity());
    resentValue -> setText(QString::number(n.humidity()));
  }
  else if(currentItem == 2){
    line -> append(-(n.time().secsTo(QTime::currentTime())),n.beam());
    resentValue -> setText(QString::number(n.beam()));
  }

  // chart -> addSeries(line);
  // chart -> createDefaultAxes();
  // chart -> setAxisX(axisX,line);
  refresh();
}

void chartWidget::pop(qint16 ID){

    refresh();
}

void chartWidget::setRange(int min,int max){
  // chart -> removeSeries(line);
  // chart -> removeAxis(axisX);

  axisX -> setRange(min,max);

  // chart -> addSeries(line);
  // chart -> createDefaultAxes();
  // chart -> setAxisX(axisX,line);
  refresh();
}

void chartWidget::setTitle(QString title){
  chart -> setTitle(title);
  refresh();
}

void chartWidget::refresh(){
}

void chartWidget::setline(QLineSeries *L){
  chart -> removeSeries(line);
  chart -> removeAxis(axisX);
  chart -> addSeries(L);
  chart -> createDefaultAxes();
  chart -> setAxisX(axisX,L);
  line = L;
}
