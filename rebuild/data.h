#include<QString>
#include<QVector>
#include<QDataStream>
#include<QTime>
class Data
{
	private:
        QVector<qint16> Value;
		QVector<bool> States;
		bool Completed=false;
		QTime Time;
		int ID;
        void node(const qint8 &s);              //辅助函数，根据int8保存各节点数据
	public:

        Data(QDataStream &s);
        QTime time();
		double Temper(int i);
		bool isOpen(int i);
		bool isCompleted();
		qint16 Id();
};
