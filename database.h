#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QString>
#include <random>
#include <QSqlTableModel>
#include <QTableView>


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
    void add_new_student(QString,QString);
    void set_math_grade(QString,QString,int);
    void set_phys_grade(QString,QString,int);
    void set_lit_grade(QString,QString,int);
    void set_chem_grade(QString,QString,int);
    void database_reader();
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

void tables :: add_new_student(QString fns,QString lns)
{
    QSqlQuery newquery;
    newquery.exec("INSERT INTO "+table_name+" VALUES('"+fns+"','"+lns+")");
}

void tables :: set_math_grade(QString fn,QString ln,int math_num)
{
    QSqlQuery newquery;
    QString num = make_string(math_num);
    newquery.exec("UPDATE "+table_name+"SET math='"+num+"' WHERE firstname='"+fn+"' AND lastname='"+ln+"'");
}

void tables :: set_phys_grade(QString fn,QString ln,int phys_num)
{
    QSqlQuery newquery;
    QString num = make_string(phys_num);
    newquery.exec("UPDATE "+table_name+"SET physics='"+num+"' WHERE firstname='"+fn+"' AND lastname='"+ln+"'");
}

void tables :: set_lit_grade(QString fn,QString ln,int lit_num)
{
    QSqlQuery newquery;
    QString num = make_string(lit_num);
    newquery.exec("UPDATE "+table_name+"SET litrature='"+num+"' WHERE firstname='"+fn+"' AND lastname='"+ln+"'");
}

void tables :: set_chem_grade(QString fn,QString ln,int chem_num)
{
    QSqlQuery newquery;
    QString num = make_string(chem_num);
    newquery.exec("UPDATE "+table_name+"SET litrature='"+num+"' WHERE firstname='"+fn+"' AND lastname='"+ln+"'");
}

void tables :: database_reader()
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("class1");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"firstname");
    model->setHeaderData(1,Qt::Horizontal,"lastname");
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

tables :: ~tables()
{
    db.close();
}



#endif // DATABASE_H
