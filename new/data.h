#ifndef DATA_H
#define DATA_H

#include<QDateTime>
#include<QDataStream>
#include<QVector>


class Data{
private:
  QDateTime timer;
  QVector<quint16> value;
  quint16 ID;
  quint16 Type;
  bool Completed=false;

public:
  Data(QDataStream &in);
  QString terminal_name();
  int type();
  double temper(int i);
  double temperature();
  double humidity();
  double beam();
  double smog();
  bool is_completed();

  quint16 terminalID();
  QDateTime time();
};

#endif
