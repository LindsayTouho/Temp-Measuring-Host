#include<QApplication>
#include"collectWindow.h"
int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    mainWindow *Window = new mainWindow;
    Window ->show();
    return app.exec();
}
