#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

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
	void showMessage(QByteArray messages);
signals:

public slots:

};
#endif
