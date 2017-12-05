#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include<QWidget>
#include<QSqlTableModel>
#include<QTableView>
#include<QSqlDatabase>

class sqlWidget:public QWidget{
private:
  QSqlTableModel *model;
  QTableView *view;
public:
  sqlWidget(QWidget *parent = nullptr,QSqlDatabase &db,int Id,int index);
  ~sqlWidget();
  void changeIndex(int index)
};
#endif
//view->hideColumn(0);  隐藏部分列
