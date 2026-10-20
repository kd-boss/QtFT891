#include "QtFT891.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtFT891 w;
    w.setWindowIcon(QIcon(":/QtFT891/IDI_ICON1"));
    w.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    
    w.show();
    return a.exec();
}
