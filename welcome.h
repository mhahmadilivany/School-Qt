#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "login.h"

class welcome : public QWidget
{
    Q_OBJECT
private:
    login w;

public:
    welcome(QWidget *parent = 0);
    QLabel *wel;
    QPushButton *ok;
    ~welcome();

public slots:
    void open_page();
};



#endif // WIDGET_H
