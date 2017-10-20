#ifndef SENDWINDOW_H
#define SENDWINDOW_H
#include<QLabel>
#include<QPushButton>
#include<QDialog>
#include<QHBoxLayout>
#include<QVBoxLayout>

class SendWindow : public QDialog
{
	Q_OBJECT;
private:
	QVBoxLayout *mainLayout=0;
	QLayout * layout[4];
	QPushButton * button [4];
	QPushButton * close=0;
        QLabel *lable[4];
public:
	SendWindow(QWidget *parent = nullptr);
	~SendWindow();
    unsigned shakeHands=0x002100FE;
    unsigned gateway = 0x002300FE;
    unsigned closeAlarm = 0x002800FE;
    unsigned manualAlarm = 0x002900FE;
signals:
	void sendding(unsigned);
public slots:
	void button1(){emit sendding(shakeHands);};
	void button2(){emit sendding(gateway);};
	void button3(){emit sendding(closeAlarm);};
	void button4(){emit sendding(manualAlarm);};
};
#endif
