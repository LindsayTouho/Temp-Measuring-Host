#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include<QWidget>
#include<QSqlTableModel>
#include<QTableView>
#include<QSqlDatabase>
#include<QString>
#include<QHBoxLayout>

class sqlWidget : public QWidget{
    Q_OBJECT
private:
  QSqlTableModel *model;
  QTableView *view;
  QString current_terminal;
  QHBoxLayout *L;
public:
  sqlWidget(QWidget *parent,QString terminal_name,QSqlDatabase &db);
  ~sqlWidget();
public slots:
  void changeTerminal(QString terminal_name);
  void refresh();
};
#endif
//view->hideColumn(0);  隐藏部分列
