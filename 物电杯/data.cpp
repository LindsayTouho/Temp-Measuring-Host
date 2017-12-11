#include"data.h"

QTime Data::time(){
  return timer;
}

int Data::temperature(){
  return ((double)Temperature) /16;
}

int Data::humidity(){
  return ((double)Humidity) /16;
}

int Data::beam(){
  return Beam;
}

int Data::smog(){
    reutrn Smog;
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

  in>>type;     //终端识别号


  in>>temp16;    //ds
  in>>temp8;


  in>>Temperature;  //温度
  in>>Humidity;   //湿度
  in>>Beam ;     //光照
  in>>Smog ;

  /*这里可能有烟雾数值*/
  /*if(type==0x0060)*/

  temp16=0;

  while(!temp16){   //之后的无用数据为0
    in>>temp16;
  }
  in>>temp16;
  timer=QTime::currentTime();
  if(temp16%16==0x66)
    Completed=true;
}

qint16 Data::terminalID(){
  return ID;
}

int Data::type(){
  return type;
}
