#include<QTreeWidgetItem>
#include<QLineSeries>
#include<QStringList>

class treeWidgetItem:public  QTreeWidgetItem{
public:
  treeWidgetItem(QStringList *list);
  void setData(QLineSeries *data);
  QLineSeries *data();
private:
  QLineSeries *data=nullptr;
}
