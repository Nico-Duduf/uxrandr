#include "uxrandr.h"

#include <QApplication>
#include <QStyleFactory>
#include "version.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(STR_COMPANYNAME);
    QCoreApplication::setOrganizationDomain(STR_COMPANYDOMAIN);
    QCoreApplication::setApplicationName(STR_PRODUCTNAME);
    QCoreApplication::setApplicationVersion(STR_VERSION);

    QApplication a(argc, argv);

    UXRandR w;
    w.show();
    return a.exec();
}
