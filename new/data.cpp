#include"data.h"
#include<QDebug>

QDateTime Data::time(){
  return timer;
}

double Data::temperature(){
  if(Type==0x0600)
      return (double)((value[0]*100)/256)/100;
  else
      return -1;
}

double Data::humidity(){
    if(Type==0x0600)
        return (double)((value[1]*100)/256)/100;
    else
        return -1;
}

double Data::beam(){
    if(Type==0x0600){
        return 256-value[2]/256;
    }
    else
        return -1;
}

double Data::smog(){
    if(Type==0x0600){
        return value[2]%256;
    }
    else
        return -1;
}

int Data::type(){
    return Type;
}

double Data::temper(int i){
    if(Type != 0x0200)
        return -1;
    if(i<8)
    {
            return (double)((int)(value[i]*0.625))/10;
    }
    else return -1;
}

Data::Data(QDataStream &in){
  quint8 temp8=0;
  quint16 temp16=0;
  while (temp8!=0x55&&!in.atEnd()) {
    in>>temp8;
  }
  if(in.atEnd())
      return;
  in>>temp8;     //数据长度
  in>>temp16;     //反馈信号

  in>>ID;        //终端号

  in>>Type;     //终端识别号


  in>>temp16;    //ds
  in>>temp8;

  for(int i=0;i<8&&!in.atEnd();++i){
      in>>temp16;
      value.push_back(temp16);
  }
  in>>temp16;
  in>>temp8;
  in>>temp8;
  if(temp8==0x66){
    Completed=true;
  }
  timer=QDateTime::currentDateTime();
}

quint16 Data::terminalID(){
  return ID;
}


bool Data::is_completed(){
  return Completed;
}

QString Data::terminal_name(){
    return (("0000"+QString::number(ID,16)).right(4).toUpper());
}
