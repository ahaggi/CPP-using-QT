#include <QApplication>
#include "mail_client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mail_client mc;
    mc.show();
    return a.exec();
}
