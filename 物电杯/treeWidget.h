#ifndef TREE_H
#define TREE_H

#include<QTreeWidget>
#include<QSqlDatabase>

class sqlWidget:public QTreeWidget{
public:
  sqlWidget();
  sqlWidget();
  void addItem(QString terminal_name);
  void removeItem(QString terminal_name);
}

#endif
