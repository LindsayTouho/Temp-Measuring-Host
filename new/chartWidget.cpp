#include"chartWidget.h"


chartWidget::chartWidget(QWidget *parent):QWidget(parent){
  resentValue = new QLabel;
  currentTime = new QLabel;
  resentValue -> setAlignment(Qt::AlignHCenter);
  currentTime -> setAlignment(Qt::AlignHCenter);


  line = new QLineSeries;     //设置折线图
  chart = new QChart;
  chart -> setMargins(QMargins(0,0,0,0));
  chart -> legend() -> hide();
  chart -> setPlotAreaBackgroundBrush(QBrush(Qt::black));
  chart -> setPlotAreaBackgroundVisible(true);
  chart -> createDefaultAxes();
  chart -> setTheme(QChart::ChartThemeQt);
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

  QTimer *refreshTimer = new QTimer;
  connect(refreshTimer,SIGNAL(timeout()),this,SLOT(refresh()));
  refreshTimer -> start(1000);
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
  setline(line);
  resentValue-> setText("<h3>最近的值："+QString::number(get_last())+"</h3>");
  currentTime -> setText("<h3>时间："+QDateTime::currentDateTime().toString("yyyy年MM月dd日 hh:mm:ss")+"</h3>");
}


void chartWidget::setline(QLineSeries *L){
  chart -> removeAxis(axisX);
  chart -> removeSeries(line);
  chart -> addSeries(L);
  chart -> createDefaultAxes();
  chart -> setAxisX(axisX,L);
  line = L;
  //print_line(L);
}

int chartWidget::get_last(){
  QVector<QPointF> v = line -> pointsVector();
  if(!v.isEmpty())
    return v.last().y();
  return 0;
}
