#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include<QWidget>
#include<QSqlTableModel>
#include<QTableView>
#include<QSqlDatabase>
#include<QString>

class sqlWidget:public QWidget{
private:
  QSqlTableModel *model;
  QTableView *view;
  QString current_terminal;
public:
  sqlWidget(QWidget *parent = nullptr,QSqlDatabase &db,QString terminal_name);
  ~sqlWidget();
public slots:
  void changeTerminal(QString terminal_name);
  void refresh();
};
#endif
//view->hideColumn(0);  隐藏部分列
