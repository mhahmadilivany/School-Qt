#include "welcome.h"
#include "login.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    welcome z;
    z.show();
    tables ab("school.db","class1");
    ab.table_completer(30);
    ab.database_reader();
    tables b("class2");
    b.database_reader();
    b.table_completer(29);
    return a.exec();
}
