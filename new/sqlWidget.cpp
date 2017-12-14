#include"sqlWidget.h"

//index == 2,3,4时为要显示的行号，为1时显示所有的行
sqlWidget::sqlWidget(QWidget *parent, QString terminal_name, QSqlDatabase &db):QWidget(parent){
  current_terminal = terminal_name;
  model = new QSqlTableModel(this,db);
  model -> setTable("data");
  model -> setSort(0,Qt::AscendingOrder);
  model -> setFilter(tr("name = \'%1\'").arg(terminal_name));
  model -> select();
  view  = new QTableView;
  view -> setModel(model);
  view -> setColumnHidden(0,true);
  L = new QHBoxLayout;
  L->addWidget(view);
  setLayout(L);
}

sqlWidget::~sqlWidget(){
  delete model;
  delete view;
}

void sqlWidget::changeTerminal(QString terminal_name){
  current_terminal = terminal_name;
  model -> setFilter(tr("name = \'%1\'").arg(terminal_name));
  model -> select();
}

void sqlWidget::refresh(){
    model->select();
}
