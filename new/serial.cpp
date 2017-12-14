#include"serial.h"

serial::serial(QString serial_name){
    S.setPortName(serial_name);
    S.setBaudRate(QSerialPort::Baud38400);
    S.setParity(QSerialPort::NoParity);
    S.setDataBits(QSerialPort::Data8);
    S.setStopBits(QSerialPort::OneStop);
    QObject::connect(&S,SIGNAL(readyRead()),this,SLOT(on_serial_readyRead()));
}

void serial::open(bool flag){
    if(flag){
        if(S.isOpen())
            return;
        else
            S.open(QIODevice::ReadWrite);
    }
    else{
        if(S.isOpen())
            S.close();
        else
            return;
    }
}

Data *serial::initData(QDataStream &in){
    Data *temp = new Data(in);
    if(!temp->is_completed()){
        free(temp);
        return nullptr;
    }
    QString = temp->terminal_name();
    QSqlQuery query;
    query.exec(
                QString("INSERT INTO data (name,timer,temperature,humidity,beam,smog） "
                "VALUES('%1','%2',%3,%4,%5,%6")
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
    Buffer.append(b);
    QDataStream temp(Buffer);
    Data *result = initData(temp);
    if(result!=nullptr){
        Buffer.clear();
        emit readed(result);
    }
}
