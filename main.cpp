#include "mzprob.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mzProb w;
    w.show();

    return a.exec();
}
