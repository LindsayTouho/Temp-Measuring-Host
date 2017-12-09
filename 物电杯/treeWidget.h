#ifndef TREE_H
#define TREE_H

#include<QTreeWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QLineSeries>
#include<QDateTime>
#include<QList>
#include"treeWidgetItem"

class treeWidget:public QTreeWidget{
  Q_OBJECT;
public:
  treeWidget(QWidget *parent = nullptr,QSqlDatabase &db);
  ~treeWidget();
private:
  QLineSeries *makeLine(QString terminal_name,int index); //2: 温度 3:湿度 4:光照
public slots:
  void refresh(QString terminal_name);
};
#endif
