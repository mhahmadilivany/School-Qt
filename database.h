#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>
#include <random>

class tables
{
private:
    QString name;
    QString table_name;
    QSqlDatabase db;

public:
    tables(QString);
    tables(QString,QString);
    void table_completer(int);
    QString rand_name();
    QString make_string(int);
    //void database_reader(QSqlDatabase db);
    ~tables();
};

tables :: tables(QString nt)
{
    table_name = nt;
}

tables :: tables(QString n,QString nt)
{
    name = n;
    table_name = nt;
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name);
    db.open();
}

QString tables :: rand_name(){
    QString a = "abcdefghijklmnopqrstuvwxyz";
    QString s = "";
    int b = rand()%3 + 4;
    for(int i=0;i<b;i++){
        int n = rand()%25;
        s += a[n];
    }
    return s;
}

QString tables :: make_string(int num)
{
    QString result;
    result.append(QString("%1").arg(num));
    return result;
}

void tables :: table_completer(int students_numbers)
{
    QSqlQuery query;
    query.exec("CREATE TABLE "+table_name+" (firstname text,lastname text,math int,physics int,litrature int,chemistry int);");
    tables t(name,table_name);
    for(int i=0;i<students_numbers;i++){
        int a = rand()%20;
        QString e = t.make_string(a);
        int b = rand()%20;
        QString f = t.make_string(b);
        int c = rand()%20;
        QString g = t.make_string(c);
        int d = rand()%20;
        QString h = t.make_string(d);
        QSqlQuery newquery;
        newquery.exec("INSERT INTO "+table_name+" VALUES('"+t.rand_name()+"','"+t.rand_name()+"',"+e+","+f+","+g+","+h+")");
    }
}

tables :: ~tables()
{
    db.close();
}



#endif // DATABASE_H
