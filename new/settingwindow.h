#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

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
#include<QMessageBox>

class settingWindow :public QDialog
{
        Q_OBJECT
public:

        settingWindow(QWidget *parent = nullptr);
        ~settingWindow();

private:
        QHBoxLayout *layout1;
        QLabel *chartRange;
        QSpinBox *timeRange;               	//统计图范围

        QHBoxLayout *layout2;
        QLabel *dataNum;
        QSpinBox *numSlider;			//本地保存数据个数

        QHBoxLayout *layout3;
        QLabel *serialName;
        QComboBox *serialPort;			//打开串口名


        QHBoxLayout *layout5;
        QPushButton *OK;
        QPushButton *Cancle;

        QVBoxLayout *mainLayout;

        void createWindow();
        void createLayout();
public slots:
        void Change();

signals:
        void settingChanged(QSettings *newSetting);
};


#endif // SETTINGWINDOW_H
