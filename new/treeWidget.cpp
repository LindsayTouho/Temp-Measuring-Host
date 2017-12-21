#include"treeWidget.h"
#include<QDebug>
treeWidget::treeWidget(QWidget * parent):QTreeWidget(parent){
    updateTime = QDateTime::currentDateTime();
   setHeaderHidden(true);
   QLineSeries *temp;;
   QSqlQuery query;
   query.exec("select distinct name from data order by name");
   while(query.next()){

     QString name = query.value(0).toString();
     QTreeWidgetItem *n = new QTreeWidgetItem(QStringList()<<name);
     QTreeWidgetItem *temperature = new QTreeWidgetItem(QStringList()<<"温度");
     temp = makeLine(name,2);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     QTreeWidgetItem *humidity = new QTreeWidgetItem(QStringList()<<"湿度");
     temp = makeLine(name,3);
     humidity -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     QTreeWidgetItem *beam = new QTreeWidgetItem(QStringList()<<"光照");
     temp = makeLine(name,4);
     beam -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     QTreeWidgetItem *smog = new QTreeWidgetItem(QStringList()<<"烟雾");
     temp = makeLine(name,5);
     smog ->setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
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
  QSettings settings;
  int max = settings.value("ram_data_num",QVariant(1000)).toInt();
  int i=0;
  while(query.next()&&i<max){
    QDateTime T = QDateTime::fromString(query.value(0).toString(),"yyyy-MM-dd hh:mm:ss");
    line -> append(-(T.secsTo(QDateTime::currentDateTime())),query.value(1).toDouble());
    ++i;
  }
  return line;
}

void treeWidget::append(Data *n) {
  QString terminal_name = n->terminal_name();
  if(findItems(terminal_name,0).isEmpty()){     //虽然这里不用makekine函数效率更高，不过懒得写了
    QTreeWidgetItem *n = new QTreeWidgetItem(QStringList()<<terminal_name);
    QLineSeries *temp;
    QTreeWidgetItem *temperature = new QTreeWidgetItem(QStringList()<<"温度");
    temp = makeLine(terminal_name,2);
    temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
    QTreeWidgetItem *humidity = new QTreeWidgetItem(QStringList()<<"湿度");
    temp = makeLine(terminal_name,3);
    humidity -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
    QTreeWidgetItem *beam = new QTreeWidgetItem(QStringList()<<"光照");
    temp = makeLine(terminal_name,4);
    beam -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
    QTreeWidgetItem *smog = new QTreeWidgetItem(QStringList()<<"烟雾");
    temp = makeLine(terminal_name,5);
    smog ->setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
    n->addChild(temperature);
    n->addChild(humidity);
    n->addChild(beam);
    n->addChild(smog);
    addTopLevelItem(n);
    repaint();
  }
  else{
    QTreeWidgetItem *const currentItem = findItems(terminal_name,0).front();
    QLineSeries *line ;
    QDateTime T = n->time();
    QSettings settings;
    line = (QLineSeries *)((currentItem->child(0))->data(0,Qt::UserRole).value<void *>());
    if(line != nullptr){
        updateLine(line);
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->temperature());
      auto vec = line->pointsVector();
      if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
          line->remove(vec.first().x(),vec.first().y());
      }
    }
    line = (QLineSeries *)((currentItem->child(1))->data(0,Qt::UserRole).value<void *>());
    if(line != nullptr){
        updateLine(line);
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->humidity());
      auto vec = line->pointsVector();
      if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
          line->remove(vec.first().x(),vec.first().y());
      }
    }
    line =  (QLineSeries *)((currentItem->child(2))->data(0,Qt::UserRole).value<void *>());
    if(line != nullptr){
        updateLine(line);
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->beam());
      auto vec = line->pointsVector();
      if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
          line->remove(vec.first().x(),vec.first().y());
      }
    }
    line =  (QLineSeries *)((currentItem->child(3))->data(0,Qt::UserRole).value<void *>());
    if(line != nullptr){
        updateLine(line);
      line -> append(-(T.secsTo(QDateTime::currentDateTime())),n->smog());
      auto vec = line->pointsVector();
      if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
          line->remove(vec.first().x(),vec.first().y());
      }
    }
  }
}

treeWidget::~treeWidget(){
}

void treeWidget::updateLine(QLineSeries *line){
    auto vec = line-> pointsVector();
    for(auto i= vec.begin();i!=vec.end();++i){
          i->rx() -=(updateTime.secsTo(QDateTime::currentDateTime()));
    }
    line->clear();
    for(auto i = vec.begin();i!=vec.end();++i){
        line->append(*i);
    }
}
//time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");
