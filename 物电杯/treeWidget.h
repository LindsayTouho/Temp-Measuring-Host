#ifndef TREE_H
#define TREE_H

#include<QTreeWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QLineSeries>
#include<QDateTime>

class treeWidget:public QTreeWidget{
public:
  treeWidget(QWidget *parent = nullptr,QSqlDatabase &db);
  ~treeWidget();
  void addItem(QString terminal_name);
  void removeItem(QString terminal_name);
private:
  QLineSeries *makeLine(QString terminal_name,int index);
};
#endif
