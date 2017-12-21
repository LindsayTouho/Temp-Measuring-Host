#include"mainWindow.h"
#include<QApplication>
#include<QCoreApplication>

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
    QCoreApplication::setOrganizationName("CST");
    QCoreApplication::setOrganizationDomain("www.zhoulinsen.xin");
    QCoreApplication::setApplicationName("Test");
	Window *window=new Window;
	window->show();
	return app.exec();
}
