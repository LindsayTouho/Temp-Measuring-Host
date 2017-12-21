#include"data.h"
#include<QDebug>

QDateTime Data::time(){
  return timer;
}

double Data::temperature(){
  return ((double)Temperature) /256;
}

double Data::humidity(){
  return ((double)Humidity) /256;
}

double Data::beam(){
  return Beam;
}

double Data::smog(){
    return Smog;
}

int Data::type(){
    return Type;
}

Data::Data(QDataStream &in){
  qint8 temp8=0;
  qint16 temp16=0;
  while (temp8!=0x55) {
    in>>temp8;
  }
  in>>temp8;     //数据长度
  in>>temp16;     //反馈信号

  in>>ID;        //终端号

  in>>Type;     //终端识别号


  in>>temp16;    //ds
  in>>temp8;


  in>>Temperature;  //温度
  in>>Humidity;   //湿度
  in>>Beam ;     //光照
  in>>Smog ;    //烟雾

  temp16=0;

  while(!temp16){   //之后的无用数据为0
    in>>temp16;
  }
  in>>temp16;
  timer=QDateTime::currentDateTime();
  if(temp16%256==0x66)
    Completed=true;
}

qint16 Data::terminalID(){
  return ID;
}


bool Data::is_completed(){
  return Completed;
}

QString Data::terminal_name(){
    return (("0000"+QString::number(ID,16)).right(4).toUpper());
}
