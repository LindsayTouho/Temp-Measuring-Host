#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QByteArray>
#include<QDataStream>
#include<QString>
#include<QObject>
#include<QSqlQuery>
#include"data.h"

class serial : public QObject{
    Q_OBJECT
public:
  serial(QString serial_name);
private:
  QSerialPort S;
  Data *initData(QDataStream &in);
  QByteArray Buffer;
public slots:
  void on_serial_readyRead();
  bool open(bool flag);
signals:
  void readed(Data *n);
};
