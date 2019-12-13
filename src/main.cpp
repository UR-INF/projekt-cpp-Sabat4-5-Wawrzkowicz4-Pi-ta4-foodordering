#include "placeordermenu.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlaceOrderMenu w;
    w.show();


    return a.exec();
}
