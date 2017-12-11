#include<QTreeWidgetItem>
#include<QLineSeries>
#include<QStringList>

class treeWidgetItem:public  QTreeWidgetItem{
  Q_OBJECT;
public slots:
  void setData(QLineSeries *data);
public:
  treeWidgetItem(QStringList *list);
  QLineSeries *data();
private:
  QLineSeries *data=nullptr;
}
