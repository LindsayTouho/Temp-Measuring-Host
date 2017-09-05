#include<Qlabel>
#include<QPushButton>
#include<QDialog>
#include<QHBoxLayout>
#include<QVBoxLayout>

class SendWindow : public QDialog
{
	Q_OBJECT;
private:
	QLabel * layout[4];
	QPushButton * button [4];

public:
	SendWindow(QDialog *parent = nullptr); 
	~SendWindow();
	enum message{shakeHands = 0xFE002100,gateway = 0xFE002300,closeAlarm = 0xFE002800,manualAlarm = 0xFE002900};
signal:
	void sendding(message);
public slots:
	void button1(){emit sendding(shakeHands);};
	void button2(){emit sendding(gateway);};
	void button3(){emit sendding(closeAlarm);};
	void button4(){emit sendding(manualAlarm);};
};
