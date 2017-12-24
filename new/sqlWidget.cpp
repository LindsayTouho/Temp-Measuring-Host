#include"sqlWidget.h"
#include<QDebug>

//index == 2,3,4时为要显示的行号，为1时显示所有的行
sqlWidget::sqlWidget(QWidget *parent, QString terminal_name, QSqlDatabase &db):QWidget(parent){
  current_terminal = terminal_name;
  model = new QSqlTableModel(this,db);
  model -> setSort(1,Qt::AscendingOrder);
  model -> select();
  view  = new QTableView;
  view -> setModel(model);
  L = new QHBoxLayout;
  L->addWidget(view);
  setLayout(L);
}

sqlWidget::~sqlWidget(){
  delete model;
  delete view;
}

void sqlWidget::changeTerminal(QString terminal_name){
  QSqlQuery query;
  query.exec(tr("SELECT COUNT(*) FROM data where name = \'%1\'").arg(terminal_name));
  query.next();
  if(query.value(0).toInt()!=0)
     model -> setTable("data");
  else
     model -> setTable("data2");
  current_terminal = terminal_name;
  model -> setFilter(tr("name = \'%1\'").arg(terminal_name));
  model -> select();
  view -> setColumnHidden(0,true);
  //qDebug()<<"change Terminal";
}

void sqlWidget::refresh(){
    //qDebug()<<"refresh";
    //changeTerminal(current_terminal);
    model->select();
}
