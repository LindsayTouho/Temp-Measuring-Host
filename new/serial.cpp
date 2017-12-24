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
    if(temp->type()==0x0600){
        query.exec(
                QString("INSERT INTO data (name,timer,temperature,humidity,beam,smog) VALUES(\'%1\',\'%2\',%3,%4,%5,%6);")
                .arg(temp->terminal_name())
                .arg(temp->time().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(QString::number(temp->temperature()))
                .arg(QString::number(temp->humidity()))
                .arg(QString::number(temp->beam()))
                .arg(QString::number(temp->smog()))
                );
    }
    else if(temp->type()==0x0200){
        query.exec(
                QString("INSERT INTO data2 (name,timer,T1,T2,T3,T4,T5,T6,T7,T8) VALUES(\'%1\',\'%2\',%3,%4,%5,%6,%7,%8,%9,%10);")
                .arg(temp->terminal_name())
                .arg(temp->time().toString("yyyy-MM-dd hh:mm:ss"))
                .arg(QString::number(temp->temper(0)))
                .arg(QString::number(temp->temper(1)))
                .arg(QString::number(temp->temper(2)))
                .arg(QString::number(temp->temper(3)))
                .arg(QString::number(temp->temper(4)))
                .arg(QString::number(temp->temper(5)))
                .arg(QString::number(temp->temper(6)))
                .arg(QString::number(temp->temper(7)))
                );
    }
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
