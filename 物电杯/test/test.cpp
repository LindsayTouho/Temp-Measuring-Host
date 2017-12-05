#include"chartWidget.h"
#include<QApplication>

int main(int argc,char *argv[]){
  QApplication app(argc,argv);
  QLineSeries *line = new QLineSeries;
  line->append(-1,1);
  line->append(-15,15);
  line->append(-30,30);
  chartWidget *view = new chartWidget;
  view -> setline(line);
  view -> setRange(-30,0);
  view->resize(1000,500);
  view -> show();
  return app.exec();
}
