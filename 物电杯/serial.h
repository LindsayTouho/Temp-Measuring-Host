#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QByteArray>
#include<QDataStream>
#include<QString>
#include"data.h"

class serial{
public:
  serial(QString serial_name);
private:
  QSerialPort S;
  Data *initData(QDataStream &in);
  QByteArray Buffer;
public slots:
  void on_serial_readyRead();
  void open(bool flag);
signals:
  void readed(Data *n);
};
