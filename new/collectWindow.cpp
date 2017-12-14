#include"collectWindow.h"

mainWindow::mainWindow(){
    resize(1000,1000);
    QCoreApplication::setOrganizationName("CSL");
    QCoreApplication::setApplicationName("Mysoft");
    createWidget();
    createLayout();
    createEvent();
    createMenu();
}

bool mainWindow::dbconnect(){
    db.setDatabaseName("data.db");
    if(db.open())
        return true;
    return false;
}

void mainWindow::createWidget(){
    tree = new treeWidget(this);
    chart = new chartWidget(this);
    sql = new sqlWidget(this,"",db);
    openCloseButton = new QPushButton(this);
    openCloseButton->setText(tr("&Open"));
    quitButton = new QPushButton(this);
    quitButton -> setText(tr("&Quit"));
}

void mainWindow::createLayout(){
    right = new QSplitter(Qt::Vertical);
    right -> addWidget(chart);
    right -> addWidget(sql);
    right -> setStretchFactor(1,1);

    center = new QSplitter(Qt::Horizontal);
    center -> addWidget(tree);
    center -> addWidget(right);
    center -> setStretchFactor(1,1);
    setCentralWidget(center);
}

void mainWindow::createEvent(){

}

void mainWindow::createMenu(){

}

void mainWindow::refresh(Data *n){

}

void mainWindow::open_close(){

}
