#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QAction>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
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
#include"settingWindow.h"
#include"sendWindow.h"
#include"debugWindow.h"
using namespace QtCharts;

class Window:public QMainWindow
{
		Q_OBJECT
	private:
		QHBoxLayout *layout1[4];
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


    	QMap<qint16 , QVector<Data*>> data;
		QSerialPort *serial=nullptr;
  		QByteArray *Buffer=nullptr;

		QChart *chart;
  		QValueAxis *axisX;
    	QValueAxis *axisY;
		QLineSeries *line;
		QChartView *view;

		QSettings setting;

        SendWindow *subWindow1 = 0;
		SettingWindow *subWindow2 = 0;
		debugWindow *subWindow3 = 0;

		QAction *sendAction;
		QAction *settingAction;
		QAction *debugAction;

		void sleep(unsigned ms);
        void createMainWindow();
        void setBuJu();
        void createEvent();
		bool addInValue(QDataStream& stream);         //串口操作，将数据试图保存
		void createMenu();                             //创建menubar
		bool readSettings();                          //读取设置
		bool dbconnect();
        void throwEvent(QString m);                           //连接数据库
		int localNum=100;

		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	public:
		Window();
		~Window();
	public slots:
		void on_Open_Close_clicked();
		void on_serial_readyRead();
        void refresh();

        void serialSend(unsigned m);

		void showSetting();
		void showSend();
		void showDebug();

    signals:
        void closewindow();
};

#endif
