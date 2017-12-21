#ifndef SENDER_H
#define SENDER_H

#include<QLabel>
#include<QPushButton>
#include<QDialog>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QVector>
#include<QDebug>

class Sender : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *mainLayout=0;
    QLayout * layout[12];
    QPushButton * button [12];
    QPushButton * close=0;
    QLabel *lable[12];
public:
    Sender(QWidget *parent = nullptr);
    ~Sender();

    QVector<unsigned> signal = {0x002100FE,0x002300FE,0x002800FE,0x002900FE,0x002400FE,0x002500FE,
                                0x002A00FE,0x002B00FE,0x002C00FE,0x002D00FE,0x002E00FE,0x002F00FE};
signals:
    void sendding(unsigned);
public slots:
    void buttonEmit0(){emit sendding(signal[0]);}
    void buttonEmit1(){emit sendding(signal[1]);}
    void buttonEmit2(){emit sendding(signal[2]);}
    void buttonEmit3(){emit sendding(signal[3]);}
    void buttonEmit4(){emit sendding(signal[4]);}
    void buttonEmit5(){emit sendding(signal[5]);}
    void buttonEmit6(){emit sendding(signal[6]);}
    void buttonEmit7(){emit sendding(signal[7]);}
    void buttonEmit8(){emit sendding(signal[8]);}
    void buttonEmit9(){emit sendding(signal[9]);}
    void buttonEmit10(){emit sendding(signal[10]);}
    void buttonEmit11(){emit sendding(signal[11]);}
};

#endif // SENDER_H
