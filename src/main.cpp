#include "mainwindow.h"
#include <QApplication>

//#include "client.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Client client;

//    CMDs::CMD_t tmp = {
//                    CMDs::CMDs_NAMES::BACK_TO_ZERO,
//                    {
//                        CONFIGS::configsNames::mmInRotation,
//                        10
//                    }
//               };

//    client.sendCmd( tmp );

    return a.exec();
}
