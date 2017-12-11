#include"treeWidget.h"

treeWidget::treeWidget(QWidget * parent,QSqlDatabase &db):QTreeWidget(parent){
   QSqlQuery query;
   QLineSeries *temp;
   query.exec("SELECT DISTINCT name FROM data");


   while(query.next()){
     QString name = query.value(0).toString();
     treeWidgetItem *n = new treeWidgetItem(QStringList()<<name);
     treeWidgetItem *temperature = new treeWidgetItem(QStringList()<<"温度");
     temp = makeLine(name,2);
     temperature -> setData(temp);
     treeWidgetItem *humidity = new treeWidgetItem(QStringList()<<"湿度");
     temp = makeLine(name,3);
     temperature -> setData(temp);
     treeWidgetItem *beam = new treeWidgetItem(QStringList()<<"光照");
     temp = makeLine(name,4);
     temperature -> setData(temp);
     n->addChild(temperature);
     n->addChild(humidity);
     n->addChild(beam);
     addTopLevelItem(n);
   }

}

QLineSeries *treeWidget::makeLine(QString terminal_name,int index){
  QSqlQuery query;
  if(index == 2){
    query.exec("SELECT timer,temperature FROM data  WHERE name = "+terminal_name);
  }
  else if(index == 3){
    query.exec("SELECT timer,humidity FROM data WHERE name = "+terminal_name);
  }
  else if(index ==4){
    query.exec("SELECT timer,beam FROM data WHERE name = "+terminal_name);
  }
  else{
    return NULL;
  };
  while(query.next()){
    QDateTime T = QDateTime::fromString(query.value(0).toString(),"yyyy-MM-ss hh:mm:ss");
    line -> append(-(T.secsTo(QDateTime::currentTime())),query.value(1).toDouble());
  }
  return line;
}

void treeWidget::refresh(Data *n) {
  QString terminal_name = QString::number(n->terminalID()).right(4);
  if(findChildren(terminal_name).isEmpty()){     //虽然这里不用makekine函数效率更高，不过懒得写了
    treeWidgetItem *n = new treeWidgetItem;
    QLineSeries *temp;
    treeWidgetItem *temperature = new treeWidgetItem(QStringList()<<"温度");
    temp = makeLine(name,2);
    temperature -> setData(temp);
    treeWidgetItem *humidity = new treeWidgetItem(QStringList()<<"湿度");
    temp = makeLine(name,3);
    temperature -> setData(temp);
    treeWidgetItem *beam = new treeWidgetItem(QStringList()<<"光照");
    temp = makeLine(name,4);
    temperature -> setData(temp);
    n->addChild(temperature);
    n->addChild(humidity);
    n->addChild(beam);
    addTopLevelItem(n);
  }
  else{
    treeWidgetItem &currentItem = findChildren(terminal_name).front();
    QLineSeries *line ;
    line = currentItem.child(0).data();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentTime())),n->temperature());
    }
    line = currentItem.child(1).data();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentTime())),n->humidity());
    }
    line = currentItem.child(2).data();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentTime())),n->beam());
    }
  }
}

//time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");
