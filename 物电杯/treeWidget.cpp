#include"treeWidget.h"

treeWidget::treeWidget(QWidget * parent,QSqlDatabase &db):QWidget(parent){
   QSqlQuery query;
   query.exec("SELECT DISTINCT name FROM data");
   while(query.next()){
     QString name = query.value(0).toString();
     treeWidgetItem *n = new treeWidgetItem(QStringList()<<name);
     treeWidgetItem *temperature = new treeWidgetItem(QStringList()<<"温度");
     treeWidgetItem *humidity = new treeWidgetItem(QStringList()<<"湿度");
     treeWidgetItem *beam = new treeWidgetItem(QStringList()<<"光照");
     n->addChild(temperature);
     n->addChild(humidity);
     n->addChild(beam);
   }
}

QLineSeries *makeLine(QString terminal_name,int index){
  QSqlQuery query;
  if(index == 2){
    query.exec("SELECT timer,temperature FROM data");
  }
  else if(index == 3){
    query.exec("SELECT timer,humidity FROM data");
  }
  else if(index ==4){
    query.exec("SELECT timer,beam FROM data");
  }
  QLineSeries *line = new QLineSeries;
  while(query.next()){
    QDateTime T = QDateTime::fromString(query.value(0).toString(),"yyyy-MM-ss hh:mm:ss");
    line -> append(-())
  }
}

//time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");
