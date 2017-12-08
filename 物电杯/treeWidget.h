#ifndef TREE_H
#define TREE_H

#include<QTreeWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QLineSeries>
#include<QDateTime>
#include"treeWidgetItem"

class treeWidget:public QTreeWidget{
  Q_OBJECT;
public:
  treeWidget(QWidget *parent = nullptr,QSqlDatabase &db);
  ~treeWidget();
private:
  QLineSeries *makeLine(QString terminal_name,int index);
public slots:
  void addItem(QString terminal_name);
};
#endif
