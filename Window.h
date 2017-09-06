//窗口布局还需要调整，保证lable和chart以同样的比例缩放


#include<QSettings>
#include<QMainWindow>
#include<QDataStream>
#include<QByteArray>
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
#include"SettingWindow.h"
#include"SendWindow.h"
#include<QAction>
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
        	QLabel * Node[8];
		QPushButton *Open_Close;
		QPushButton *Quit;

		SendWindow *subWindow1;
		SettingWindow *subWindow2;

        	QMap<qint16 , QVector<Data*>> data;
		QSerialPort *serial;
        	QByteArray *Buffer;

		QChart *chart;
        	QValueAxis *axisX;
       		QValueAxis *axisY;
		QLineSeries *line;
		QChartView *view;

		QSettings *setting;

		QAction *sendAction;
		QAction *settingAction;

		void sleep(unsigned ms);
		bool addInValue(QDatastream& stream);
		void creatMenu();

	public:
		Window();
		~Window();
	public slots:
		void on_Open_Close_clicked();
		void on_serial_readyRead();
        	void refresh();

		void serialSend(SendWindow::message m);
		void saveSetting(QSettings *newSetting);

		void showSetting();
		void showSend();
};
