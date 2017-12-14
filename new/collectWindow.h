#include<QMainWindow>
#include<QSplitter>
#include<QSqlDatabase>
#include<QSettings>
#include<QPushButton>
#include<QCoreApplication>
#include"data.h"
#include"chartWidget.h"
#include"serial.h"
#include"sqlWidget.h"
#include"treeWidget.h"

class mainWindow: public QMainWindow{
private:
    QSettings setting;
    serial *S;
    treeWidget *tree;
    chartWidget *chart;
    sqlWidget *sql;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSplitter *right;
    QSplitter *center;
    QPushButton *openCloseButton;
    QPushButton *quitButton;

    bool is_connect = false;

    bool dbconnect();
    void createWidget();
    void createLayout();
    void createEvent();
    void createMenu();
public:
    mainWindow();
    ~mainWindow();
public slots:
    void refresh(Data *n);
    void open_close();
};
