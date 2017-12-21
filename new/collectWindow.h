#include<QMainWindow>
#include<QSplitter>
#include<QSqlDatabase>
#include<QSettings>
#include<QPushButton>
#include<QCoreApplication>
#include<QMenuBar>
#include<QAction>
#include<QTextEdit>
#include"data.h"
#include"chartWidget.h"
#include"serial.h"
#include"sqlWidget.h"
#include"treeWidget.h"
#include"settingwindow.h"
#include"sender.h"
#include"debuger.h"


class mainWindow:public QMainWindow{
    Q_OBJECT
private:
    QSettings setting;
    serial *S = nullptr;
    treeWidget *tree;
    chartWidget *chart;
    sqlWidget *sql;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QPushButton *openCloseButton;
    QPushButton *quitButton;

    QSplitter *right;
    QSplitter *center;
    QWidget *mainWidget;
    QHBoxLayout *buttom;
    QVBoxLayout *mainLayout;

    QAction *settingAction;
    settingWindow *settingWidget=nullptr;
    QAction *senderAction;
    Sender *senderWidget=new Sender;
    QAction *debugerAction;
    debugWindow *debugeWidget=nullptr;

    QTextEdit *clarmWidget;

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
    //void refresh(Data *n);
    void open_close();
    void readSetting();
    void changeTable(QTreeWidgetItem* item,int cloum);
    void changeChart(QTreeWidgetItem* item,int cloum);
    void showSetting();
    void showSender();
    void showDebuger();
    //void insertToDb(Data *n);
    void serialSend(unsigned data);
    void checkClarm(Data *n);
};
