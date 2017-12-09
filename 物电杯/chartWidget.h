#ifndef CHART_H
#define CHART_H
#include"data.h" //数据类头文件
#include<QString>
#include<QWidget>   //Gui 头文件
#include<QLabel>
#include<QComboBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QChart>
#include<QLineSeries>  //折线图头文件
#include<QValueAxis>
#include<QChartView>
#include<QDebug>
#include<QVector>
#include<QPointF>
#include<QDateTime>
#include<QTimer>
using namespace QtCharts;


class chartWidget : public QWidget{
  Q_OBJECT;
public slots:
  void setline(QLineSeries *L);
  void setRange(int min,int max);
  void setTitle(QString title);
  void refresh();

public:
  chartWidget(QWidget *parent = nullptr,int Item=0);
  ~chartWidget();

private:
         //私有函数
  int get_last();

  qint16 currentID;

  int currentItem=0;

  QLabel *resentValue;    //视图
  QLabel *currentTime;

  QHBoxLayout *headLayout; //布局
  QVBoxLayout *mainLayout;

  QChart *chart;       //折线图
  QValueAxis *axisX;
  // QValueAxis *axisY;
  QLineSeries *line=nullptr;
  QChartView *view;
};
#endif
