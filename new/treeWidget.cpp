#include"treeWidget.h"
#include<QDebug>
#include<QSqlError>
treeWidget::treeWidget(QWidget * parent):QTreeWidget(parent){
   setHeaderHidden(true);
   QLineSeries *temp;;
   QSqlQuery query;
   query.exec("select distinct name from data order by name");
   while(query.next()){

     QString name = query.value(0).toString();
     treeWidgetItem *n = new treeWidgetItem(QStringList()<<name);
     treeWidgetItem *temperature = new treeWidgetItem(QStringList()<<"温度");
     temp = makeLine(name,2);
     temperature -> setData(temp);
     treeWidgetItem *humidity = new treeWidgetItem(QStringList()<<"湿度");
     temp = makeLine(name,3);
     humidity -> setData(temp);
     treeWidgetItem *beam = new treeWidgetItem(QStringList()<<"光照");
     temp = makeLine(name,4);
     beam -> setData(temp);
     treeWidgetItem *smog = new treeWidgetItem(QStringList()<<"烟雾");
     temp = makeLine(name,5);
     smog ->setData(temp);
     n->addChild(temperature);
     n->addChild(humidity);
     n->addChild(beam);
     n->addChild(smog);
     addTopLevelItem(n);
   }

}

QLineSeries *treeWidget::makeLine(QString terminal_name,int index){
  QLineSeries *line = new QLineSeries;
  QSqlQuery query;
  if(index == 2){
    query.exec("SELECT timer,temperature FROM data  WHERE name = \'"+terminal_name+"\' order by timer");
  }
  else if(index == 3){
    query.exec("SELECT timer,humidity FROM data WHERE name = \'"+terminal_name+"\' order by timer");
  }
  else if(index ==4){
    query.exec("SELECT timer,beam FROM data WHERE name = \'"+terminal_name+"\' order by timer");
  }
  else if(index ==5){
    query.exec("SELECT timer,smog FROM data WHERE name = \'"+terminal_name+"\' order by timer");
  }
  else{
    return NULL;
  };
  int i=0;
  while(query.next()&&i<1000){                      //这里需要用settings
    QDateTime T = QDateTime::fromString(query.value(0).toString(),"yyyy-MM-dd hh:mm:ss");
    line -> append(-(T.secsTo(QDateTime::currentDateTime()))/60,query.value(1).toDouble());
    ++i;
  }
  return line;
}

void treeWidget::append(Data *n) {
  QString terminal_name = n->terminal_name();
  if(findChildren<treeWidgetItem*>(terminal_name).front()){     //虽然这里不用makekine函数效率更高，不过懒得写了
    treeWidgetItem *n = new treeWidgetItem(QStringList()<<terminal_name);
    QLineSeries *temp;
    treeWidgetItem *temperature = new treeWidgetItem(QStringList()<<"温度");
    temp = makeLine(terminal_name,2);
    temperature -> setData(temp);
    treeWidgetItem *humidity = new treeWidgetItem(QStringList()<<"湿度");
    temp = makeLine(terminal_name,3);
    temperature -> setData(temp);
    treeWidgetItem *beam = new treeWidgetItem(QStringList()<<"光照");
    temp = makeLine(terminal_name,4);
    temperature -> setData(temp);
    treeWidgetItem *smog = new treeWidgetItem(QStringList()<<"烟雾");
    temp = makeLine(terminal_name,5);
    smog ->setData(temp);
    n->addChild(temperature);
    n->addChild(humidity);
    n->addChild(beam);
    addTopLevelItem(n);
  }
  else{
    treeWidgetItem *const currentItem = findChildren<treeWidgetItem *>(terminal_name).front();
    QLineSeries *line ;
    line = ((treeWidgetItem*)currentItem->child(0))->data();
    QDateTime T = n->time();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->temperature());
    }
    line = ((treeWidgetItem*)currentItem->child(1))->data();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->humidity());
    }
    line = ((treeWidgetItem*)currentItem->child(2))->data();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->beam());
    }
    line = ((treeWidgetItem*)currentItem->child(3))->data();
    if(line != nullptr){
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->smog());
    }
  }
}

treeWidget::~treeWidget(){
}

//time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");
