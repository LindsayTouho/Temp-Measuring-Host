#include"serial.h"
#include<QDebug>
#include<QSqlError>

serial::serial(QString serial_name){
    S.setPortName(serial_name);
    S.setBaudRate(QSerialPort::Baud38400);
    S.setParity(QSerialPort::NoParity);
    S.setDataBits(QSerialPort::Data8);
    S.setStopBits(QSerialPort::OneStop);
    connect(&S,SIGNAL(readyRead()),this,SLOT(on_serial_readyRead()));
}

bool serial::open(bool flag){
    if(flag){
        if(S.isOpen())
            return true;
        else{
            return S.open(QIODevice::ReadWrite);
          }
    }
    else{
        if(S.isOpen()){
            S.close();
        }
        return false;
    }
}

Data *serial::initData(QDataStream &in){
    Data *temp = new Data(in);
    if(!temp->is_completed()){
        free(temp);
        return nullptr;
    }
    QSqlQuery query;
    query.exec(
                QString("INSERT INTO data (name,timer,temperature,humidity,beam,smog) VALUES(\'%1\',\'%2\',%3,%4,%5,%6);")
                .arg(temp->terminal_name())
                .arg(temp->time().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(QString::number(temp->temperature()))
                .arg(QString::number(temp->humidity()))
                .arg(QString::number(temp->beam()))
                .arg(QString::number(temp->smog()))
                );
    return temp;
}

void serial::on_serial_readyRead(){
    QByteArray b;
    b=S.readAll();
    emit originMessage(b);
    Buffer.append(b);
    QDataStream temp(Buffer);
    Data *result = initData(temp);
    if(result!=nullptr){
        Buffer.clear();
        emit readed(result);
    }

}

qint64 serial::write(QByteArray data){
    return S.write(data);
}

bool serial::isOpen(){
    return S.isOpen();
}
