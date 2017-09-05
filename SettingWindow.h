//Seting用到的函数有 setValue(QStirng,QVariant)和 value(QStirng) 
//string 应该是用来标记的设置名，variant可以转换成其他的数据类型




#include<QString>
#include<QDialog>
#include<QSpinBox>
#include<QComboBox>
#include<QLineEdit>
#include<QSettings>
#include<QWidget>
#include<QSerialPortInfo>
#include<QPushButton>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>

class SettingWindow : public QDialog
{
	Q_OBJECT;
public:

	SettingWindow(QDialog *parent = nullptr,QSettings *oldsetting=nullptr);
	~SettingWindow();

private:
	QHBoxLayout *layout1;
	QLabel *chartRange;
	QSpinBox *timeRange;               	//统计图范围
	QComboBox *timeUnit;

	QHBoxLayout *layout2;
	QLabel *dataNum;
	QSpinBox *numSlider;			//本地保存数据个数

	QHBoxLayout *layout3;
	QLabel *serialName;
	QComboBox *serialPort;			//打开串口名

	QVBoxLayout *layout4;
	QLabel *database;
	QHBoxLayout *layout6;
	QLabel *host;
	QLineEdit *hostname;			//数据库设置
	QHBoxLayout *layout7;
	QLabel *user;
	QLineEdit *username;
	QHBoxLayout *layout8;
	QLabel *pass;
	QLineEdit *passwd;
	QHBoxLayout *layout9;
	QLabel *dataname;
	QLineEdit *databasename;

	QHBoxLayout *layout5;
	QPushButton *OK;
	QPushButton *Cancle;

	QVBoxLayout *mainLayout;

public slots:
	void Change();

signals:
	void settingChanged(QSettings newSetting);
};

