#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include<QTextEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QString>
#include<QWidget>
#include<QDialog>

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
	void showMessage(QString *messages);
signals:

public slots:

};
#endif
