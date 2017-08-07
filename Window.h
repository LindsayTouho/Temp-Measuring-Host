//窗口布局还需要调整，保证lable和chart以同样的比例缩放


#include<QMainWindow>
#include<QDataStream>
#include<QSerialPort>
#include<QMenuBar>
#include<QLabel>
#include<QPushButton>
#include<QComboBox>  //QT += widgets
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>
#include<QRect>
#include<QSerialPortInfo>
#include<QTime>
#include<QCoreApplication>
#include<QChart>
#include<QValueAxis>
#include<QChartView>
#include<QLineSeries>
#include<QString>
#include"data.h"
using namespace QtCharts;

class Window:public QMainWindow
{
		Q_OBJECT
	private:
		QHBoxLayout *layout1[4];     //attention
		QVBoxLayout *layout2;
		QHBoxLayout *layout3;
		QHBoxLayout *layout4;
		QWidget *mainWidget;
		QVBoxLayout *mainLayout;
		QComboBox *Terminal;
		QComboBox *nodeBox;
		QLabel *valueTime;
        	QLabel * Node[8];
		QPushButton *Open_Close;
		QPushButton *Quit;
        	QMap<qint16 , QVector<Data*>> data;
		QSerialPort *serial;
        	QDataStream *Buffer;

		QChart *chart;
        	QValueAxis *axisX;
       		QValueAxis *axisY;
		QLineSeries *line;
		QChartView *view;
		void sleep(unsigned ms);
		bool addInValue();

	public:
		Window();
		~Window();
	public slots:
		void on_Open_Close_clicked();
		void on_serial_readyRead();
        	void refresh();
};
