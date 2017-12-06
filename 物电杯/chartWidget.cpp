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




void chartWidget::setRange(int min,int max){

  axisX -> setRange(min,max);

  refresh();
}

void chartWidget::setTitle(QString title){
  chart -> setTitle(title);
  refresh();
}

void chartWidget::refresh(){
  resentValue-> setText(QString::number(get_last()));
}


void chartWidget::setline(QLineSeries *L){
  chart -> removeSeries(line);
  chart -> removeAxis(axisX);
  chart -> addSeries(L);
  chart -> createDefaultAxes();
  chart -> setAxisX(axisX,L);
  line = L;
  print_line(L);
}

int chartWidget::get_last(){
  QVector<QPointF> v = line -> pointsVector();
  return v.last().y();
}
