#include<QTreeWidgetItem>
#include<QLineSeries>
#include<QStringList>
#include<QItemDelegate>
using namespace QtCharts;
class treeWidgetItem: public QTreeWidgetItem{
  Q_OBJECT
public slots:
  void setData(QLineSeries *data);
public:
  treeWidgetItem(QStringList list);
  treeWidgetItem();
  QLineSeries *data();
private:
  QLineSeries *Data=nullptr;
};
