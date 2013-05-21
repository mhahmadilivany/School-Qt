#include "welcome.h"
#include "login.h"

welcome::welcome(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Welcome");
    this->resize(250,120);
    wel = new QLabel("Welcome to your program",this);
    wel->setGeometry(65,30,150,20);
    ok = new QPushButton("Enter",this);
    ok->setGeometry(95,70,60,23);
    connect(ok,SIGNAL(clicked()),this,SLOT(open_page()));
}
void welcome :: open_page()
{
    this->w.show();
    this->close();
}
welcome::~welcome()
{
}
