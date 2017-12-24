#include"treeWidget.h"
#include<QDebug>
#include<QSqlError>



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


   query.exec("select distinct name from data2 order by name");
   while(query.next()){

     QString name = query.value(0).toString();
     QTreeWidgetItem *n = new QTreeWidgetItem(QStringList()<<name);

     QTreeWidgetItem *temperature = new QTreeWidgetItem(QStringList()<<"温度1");
     temp = makeTemperLine(name,1);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度2");
     temp = makeTemperLine(name,2);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度3");
     temp = makeTemperLine(name,3);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度4");
     temp = makeTemperLine(name,4);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度5");
     temp = makeTemperLine(name,5);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度6");
     temp = makeTemperLine(name,6);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度7");
     temp = makeTemperLine(name,7);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     temperature = new QTreeWidgetItem(QStringList()<<"温度8");
     temp = makeTemperLine(name,8);
     temperature -> setData(0,Qt::UserRole,QVariant::fromValue((void *)temp));
     n->addChild(temperature);

     addTopLevelItem(n);
   }

}

QLineSeries *treeWidget::makeLine(QString terminal_name,int index){
  QLineSeries *line = new QLineSeries;
  QSqlQuery query;
  QSettings setting;
  int max = setting.value("ram_data_num",QVariant(1000)).toInt();
  if(index == 2){
    query.exec(tr("SELECT timer,temperature FROM data  WHERE name = \'%2\' order by timer desc limit %1").arg(QString::number(max)).arg(terminal_name));
  }
  else if(index == 3){
    query.exec(tr("SELECT timer,humidity FROM data  WHERE name = \'%2\' order by timer desc limit %1").arg(QString::number(max)).arg(terminal_name));
  }
  else if(index ==4){
    query.exec(tr("SELECT timer,beam FROM data  WHERE name = \'%2\' order by timer desc limit %1").arg(QString::number(max)).arg(terminal_name));
  }
  else if(index ==5){
    query.exec(tr("SELECT timer,smog FROM data  WHERE name = \'%2\' order by timer desc limit %1").arg(QString::number(max)).arg(terminal_name));
  }
  else{
    return NULL;
  };
  while(query.next()){
    QDateTime T = QDateTime::fromString(query.value(0).toString(),"yyyy-MM-dd hh:mm:ss");
    line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),query.value(1).toDouble());
  }
  reserveLine(line);
  return line;
}

void treeWidget::append(Data *n) {
    QString terminal_name = n->terminal_name();
    if(findItems(terminal_name,0).isEmpty()){     //虽然这里不用makekine函数效率更高，不过懒得写了
        if(n->type()==0x0600){
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
      else if(n->type() == 0x0200){
            qDebug()<<"append";
            QTreeWidgetItem *n = new QTreeWidgetItem(QStringList()<<terminal_name);
            QLineSeries *line;
            QTreeWidgetItem *temp;
            for(int i=0;i<8;++i){
                temp = new QTreeWidgetItem(QStringList()<<tr("温度%1").arg(QString::number(i+1)));
                line = makeTemperLine(terminal_name,i+1);
                temp->setData(0,Qt::UserRole,QVariant::fromValue((void *)line));
                n->addChild(temp);
            }
            addTopLevelItem(n);
            repaint();
        }
  }
  else{
        QTreeWidgetItem *const currentItem = findItems(terminal_name,0).front();
        QLineSeries *line ;
        QDateTime T = n->time();
        QSettings settings;
        if(currentItem->childCount()==4){
            line = (QLineSeries *)((currentItem->child(0))->data(0,Qt::UserRole).value<void *>());
            if(line != nullptr){
                line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),n->temperature());
                auto vec = line->pointsVector();
                if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
                    line->remove(vec.first().x(),vec.first().y());
                }
            }
            line = (QLineSeries *)((currentItem->child(1))->data(0,Qt::UserRole).value<void *>());
            if(line != nullptr){
                line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),n->humidity());
                auto vec = line->pointsVector();
                if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
                    line->remove(vec.first().x(),vec.first().y());
                }
            }
            line =  (QLineSeries *)((currentItem->child(2))->data(0,Qt::UserRole).value<void *>());
            if(line != nullptr){
                line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),n->beam());
                auto vec = line->pointsVector();
                if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
                    line->remove(vec.first().x(),vec.first().y());
                }
            }
            line =  (QLineSeries *)((currentItem->child(3))->data(0,Qt::UserRole).value<void *>());
            if(line != nullptr){
                line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),n->smog());
                auto vec = line->pointsVector();
                if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
                    line->remove(vec.first().x(),vec.first().y());
                }
            }
        }
        else if(currentItem->childCount()==8){
            for(int i=0;i<8;i++){
                line =  (QLineSeries *)((currentItem->child(i))->data(0,Qt::UserRole).value<void *>());
                line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),n->temper(i));
                auto vec = line->pointsVector();
                if(vec.count()>(settings.value("ram_data_num",QVariant(1000)).toInt())){
                    line->remove(vec.first().x(),vec.first().y());
                }
            }
        }
    }
}

treeWidget::~treeWidget(){
}

//time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");

QLineSeries *treeWidget::makeTemperLine(QString terminal_name, int index){
    QLineSeries *line = new QLineSeries;
    QSqlQuery query;
    QSettings setting;
    int max = setting.value("ram_data_num",QVariant(1000)).toInt();
    query.exec(tr("SELECT timer,T%2 FROM data2  WHERE name = \'%3\' order by timer desc limit %1").arg(QString::number(max)).arg(QString::number(index)).arg(terminal_name));
    while(query.next()){
      QDateTime T = QDateTime::fromString(query.value(0).toString(),"yyyy-MM-dd hh:mm:ss");
      line -> append(-((double)(T.secsTo(QDateTime::currentDateTime()))/60),query.value(1).toDouble());
    }
    reserveLine(line);
    return line;
}

void treeWidget::reserveLine(QLineSeries *line){
    auto vec = line->pointsVector();
    line ->clear();
    for(auto i = vec.end()-1;i!=vec.begin()-1;--i){
        line -> append(i->x(),i->y());
    }
}
