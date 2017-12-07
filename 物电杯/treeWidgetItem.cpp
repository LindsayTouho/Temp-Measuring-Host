#include"treeWidgetItem.h"

treeWidgetItem::treeWidgetItem(QStringList *list):QTreeWidgetItem(list){
}

void treeWidgetItem::setData(QLineSeries *data){
  Data = data;
}

QLineSeries treeWidgetItem::data(){
  return Data;
}
