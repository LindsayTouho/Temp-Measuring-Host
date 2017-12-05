#include"sqlWidget.h"

//index == 2,3,4时为要显示的行号，为1时显示所有的行
sqlWidget::sqlWidget(QWidget *parent,QSqlDatabase &db,QString terminal_name,int index):QWidget(parent){
  model = new QSqlTableModel(this,db);
  model -> setTable("data");
  model -> setSort(0,Qt::AscendingOrder);
  model -> setFilter(tr("name = '%1'".arg(terminal_name)));
  model -> select();
  view  = new QTableView;
  view -> setModel(model);
  view -> setColumnHodden(0,true);
  if(index!=1){
    view -> setColumnHodden(2,true);
    view -> setColumnHodden(3,true);
    view -> setColumnHodden(4,true);
    view -> setColumnHodden(index,false);
  }
  setCenterWidget(view);
}

sqlWidget::~sqlWidget(){
  delete model;
  delete view;
}

sqlWidget::changeIndex(int index){
  view -> setColumnHodden(0,true);
  if(index!=1){
    view -> setColumnHodden(2,true);
    view -> setColumnHodden(3,true);
    view -> setColumnHodden(4,true);
    view -> setColumnHodden(index,false);
  }
}
