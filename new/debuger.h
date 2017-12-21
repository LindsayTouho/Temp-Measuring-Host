#ifndef DEBUGER_H
#define DEBUGER_H

#include<QTextEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QString>
#include<QWidget>
#include<QDialog>
#include<QByteArray>

class debugWindow : public QDialog{
    Q_OBJECT;
private:
    QTextEdit *showWidget;
    QPushButton *clearButton;
    QPushButton *quitButton;
    QHBoxLayout *buttomLayout;
    QVBoxLayout *mainLayout;
public:
    debugWindow(QWidget *parent = nullptr);
    ~debugWindow();

signals:

public slots:
    void showMessage(QByteArray messages);
};

#endif // DEBUGER_H
