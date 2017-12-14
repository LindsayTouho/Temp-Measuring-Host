#ifndef DATA_H
#define DATA_H

#include<QDateTime>
#include<QDataStream>


class Data{
private:
  QDateTime timer;
  qint16 Temperature;     //数据简单的保存编码后的温度，解码在获取数据的接口函数里面做
  qint16 Humidity;
  qint8 Beam;
  qint8 Smog;
  qint16 ID;
  qint16 Type;
  bool Completed=false;

public:
  Data(QDataStream &in);
  QString terminal_name();
  int type();
  int temperature();
  int humidity();
  int beam();
  int smog();
  bool is_completed();

  qint16 terminalID();
  QDateTime time();
};

#endif
