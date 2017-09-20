#include<QString> //QT+=core
#include<QVector>
#include<QDataStream>
#include<QTime>
class Data
{
	private:
        QVector<qint16> Value;
		QVector<bool> States;
		bool Completed;
		QTime Time;
		int Size;
		int ID;	
        void node(const qint8 &s);
	public:
		QTime time();
        Data(QDataStream &s);
		double Temper(int i);
		bool isOpen(int i);
		bool isCompleted();
		qint16 Id();
};
