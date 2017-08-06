#include<QDialog>
#include<QSpinBox>
#include<QComboBox>
#include<QLineEdit>
#include<QSetting>
#include<QWidget>

class SettingWindow : public QDialog
{
	SettingWindow(QDialog *parent = nullptr);
	~SettingWindow();

private:
	QSpinBox *timeRange;               	//统计图范围
	QComboBox *timeUnit;

	int localData = 100;			//本地保存数据个数

	QComboBox *serialPort;			//打开串口名

	QLineEdit *hostname;			//数据库设置
	QLineEdit *username;
	QLineEdit *passwd;
	QLineEdit *databasename;

	QSetting *setting;

public:

}

