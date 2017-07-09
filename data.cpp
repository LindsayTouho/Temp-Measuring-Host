#include"data.h"
#include<iostream>
using namespace std;

void Data::node(const qint8 &s)
{
	int i=0;
	int d=1;
	States.resize(8);
	while(i!=8)
	{
		if((d<<i)==((d<<i)&s))
		{
			States[i]=false;              //0 means open,1 means closed
		}
		else
			States[i]=true;
		++i;
	}
}
Data::Data(QDataStream &s)
{
    	Completed=false;
	Time=QTime::currentTime();
    	int site=0;
	qint8 temp8=0;
	qint16 temp16=1;
    	while(temp8!=85&&!s.atEnd())
    	{
       		s>>temp8;                      //throw unuseful data
    	}
    	site++;
    	if(s.atEnd())
            return;
   	s>>temp8;
	++site;
	Size=int(temp8);              //length
    	s>>temp16;                    //don't used

	//
	//
	//
	//
	//
	site+=2;
    	s>>temp16;
    	ID=temp16;
	site+=2;

    	s>>temp16;
	//
	//
	//
	//
	//
	site+=2;
   	s>>temp16;
	//
	//
	//
	//
	//
	site+=2;
    	s>>temp8;
   	node(temp8);
    	++site;
    	int i=0;

    	while(!s.atEnd()&&site<Size-2)
	{
        s>>temp16;
        Value.push_back(temp16);
	site+=2;
	++i;
    	}
    	s>>temp8;
   	++site;
    	s>>temp8;
    	++site;
    	if(site==Size&&temp8==102)
		Completed=true;
    	else
    	{
       		Completed=false;
    	}
}
QTime Data::time()
{
	return Time;
}
double Data::Temper(int i)
{
	if(i<8)
	{
        return Value[i]*0.0625;
	}
	else return 0;
}
bool Data::isOpen(int i)
{
	if(i<(Size-8)/2)                      // !!! ???
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

