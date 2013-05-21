#include "login.h"

login::login(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Login");
    this->resize(300,150);
    user = new QLabel("insert your username :",this);
    user->setGeometry(10,20,120,20);
    pass = new QLabel("insert your password :",this);
    pass->setGeometry(10,50,120,20);
    inuser = new QLineEdit(this);
    inuser->setGeometry(130,20,150,20);
    inpass = new QLineEdit(this);
    inpass->setGeometry(130,50,150,20);
    inpass->setEchoMode(QLineEdit :: Password);
    showpass = new QCheckBox("show password",this);
    showpass->setGeometry(130,80,100,15);
    connect(showpass,SIGNAL(stateChanged(int)),this,SLOT(showpassword()));
    ok = new QPushButton("login",this);
    ok->setGeometry(125,110,50,25);
    reg = new QPushButton("quit",this);
    reg->setGeometry(180,110,50,25);
    connect(reg,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(checkpass()));
    /*if(inuser->text() == "nazem" && inpass->text() == "1234"){
        connect(ok,SIGNAL(clicked()),this,SLOT(open_npage()));
    }
    else if(inuser->text() == "teacher" && inpass->text() == "12345"){
        connect(ok,SIGNAL(clicked()),this,SLOT(open_tpage()));
    }*/
}

void login :: checkpass()
{
    message = new QMessageBox;
    if(inuser->text() == "nazem" && inpass->text() == "1234"){
        message->warning(this,"Entered","you are logged in as Provost");
        this->n.show();
        this->close();
    }
    else if(inuser->text() == "teacher" && inpass->text() == "12345"){
        message->warning(this,"Entered","you are logged in as Teacher");
        this->t.show();
        this->close();
    }
    else{
        message->warning(this,"warning","the username or password is incorrect");
    }
}

void login :: showpassword()
{
    inpass->setEchoMode(showpass->checkState()==Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

/*void login :: open_tpage()
{
    this->t.show();
    this->close();
}

void login :: open_npage()
{
    this->n.show();
    this->close();
}
*/


login::~login()
{
}
