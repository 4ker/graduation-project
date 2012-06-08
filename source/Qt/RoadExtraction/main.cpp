#include <QtGui/QApplication>
#include <QTextCodec>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  //解决中文乱码
    QTextCodec *codec = QTextCodec::codecForName("System");

    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
 /*
    //a.setStyle("cleanlooks");

    QTranslator translator;
    translator.load("zh_CN");
    a.installTranslator(&translator);
*/
    MainWindow w;
    w.show();
    
    return a.exec();
}
