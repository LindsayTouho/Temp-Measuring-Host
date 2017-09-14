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
	unsigned shakeHands=0xFE002100;
	unsigned gateway = 0xFE002300;
	unsigned closeAlarm = 0xFE002800;
	unsigned manualAlarm = (0xFE002900);
signals:
	void sendding(unsigned);
public slots:
	void button1(){emit sendding(shakeHands);};
	void button2(){emit sendding(gateway);};
	void button3(){emit sendding(closeAlarm);};
	void button4(){emit sendding(manualAlarm);};
};
