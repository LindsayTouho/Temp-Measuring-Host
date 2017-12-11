#ifndef DATA_H
#define DATA_H

#include<QTime>
#include<QDataStream>


class Data{
private:
  QTime timer;
  qint16 Temperature;     //数据简单的保存编码后的温度，解码在获取数据的接口函数里面做
  qint16 Humidity;
  qint8 Beam;
  qint8 Smog;
  qint16 ID;
  qint16 type;
  bool Completed=false;

public:
  Data(QDataStream &in);
  int type();
  int temperature();
  int humidity();
  int beam();
  int smog();

  qint16 terminalID();
  QTime time();
};

#endif
