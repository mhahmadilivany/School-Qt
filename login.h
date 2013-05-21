#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include "nazem.h"
#include "teacher.h"


class login : public QWidget
{
    Q_OBJECT

private:
    nazem n;
    teacher t;

public:
    login(QWidget *parent = 0);
    QLabel *user,*pass;
    QLineEdit *inuser,*inpass;
    QCheckBox *showpass;
    QPushButton *ok,*reg;
    QMessageBox *message;
    ~login();

public slots:
    void checkpass();
    void showpassword();
  //  void open_tpage();
    //void open_npage();
};




#endif // LOGIN_H
