#include"data.h"


void Data::node(const qint8 &s)			 //辅助函数，根据int8保存各节点数据
{
	int i=0;
	int d=1;
	States.resize(8);
	while(i!=8)
	{
		if((d<<i)==((d<<i)&s))				  //0代表连接，1代表断开
		{
			States[i]=false;
		}
		else
			States[i]=true;
		++i;
	}
}

Data::~Data(){
}

Data::Data(QDataStream &s)
{
    	Completed=false;
	    Time=QTime::currentTime();
	    qint8 temp8=0;
	    qint16 temp16=1;
    	while(temp8!=0x55&&!s.atEnd())
    	{
       		s>>temp8;                              //1
    	}
     	s>>temp8;                                 //2
    	s>>temp16;                                //3，4

    	s>>temp16;                                 //5，6
    	ID=temp16;

    	s>>temp16;                                //7.8
     	s>>temp16;                                //9，10

    	s>>temp8;                                  //11
      	node(temp8);


        for(int i=0;i!=8 && !s.atEnd();++i)         //12，27
     	{
            s>>temp16;
            Value.push_back(temp16);
    	}
    	s>>temp8;                                  //28
        s>>temp16;                                  //29,30
		Father = temp16;

    	s>>temp8;                                  //31
        if(temp8==0x66)
		    Completed=true;
    	else
            Completed=false;
}

QTime Data::time()
{
	return Time;
}

double Data::Temper(int i)
{
	if(i<8)
	{
            return (double)((int)(Value[i]*0.625))/10;
	}
	else return -1;
}

bool Data::isOpen(int i)
{
	if(i<8)
	{
		return States[i];
	}
	else return 0;
}

bool Data::isCompleted()
{
	return Completed;
}

qint16 Data::Id()
{
	return ID;
}

qint16 Data::father(){
	return Father;
}
