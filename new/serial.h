#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QByteArray>
#include<QDataStream>
#include<QString>
#include<QObject>
#include<QSqlQuery>
#include<QRegExp>
#include<QByteArray>
#include"data.h"

class serial : public QObject{
    Q_OBJECT
public:
  serial(QString serial_name);
  bool isOpen();
  void test();
private:
  QSerialPort S;
  Data *initData(QDataStream &in);
  QByteArray Buffer;

public slots:
  void on_serial_readyRead();
  bool open(bool flag);
  qint64 write(QByteArray data);
signals:
  void readed(Data*);
  void originMessage(QByteArray message);
};
