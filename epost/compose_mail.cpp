#include "compose_mail.h"

compose_mail::compose_mail(QWidget *parent): QWidget(parent){

    to_label = new QLabel("To:   ");
    sub_label = new QLabel("Subject: ");
    to_text = new QLineEdit();
    sub_text = new QLineEdit();
    msg = new QTextEdit();
    send_button = new QPushButton("Send");
    cancel_button = new QPushButton("Cancel");

    top_layout = new QGridLayout();
    main_layout = new QVBoxLayout(this);
    buttom_layout = new QHBoxLayout();

    top_layout->addWidget(to_label,0,0,1,1);
    top_layout->addWidget(to_text,0,1,1,5);
    top_layout->addWidget(sub_label,1,0,1,1);
    top_layout->addWidget(sub_text,1,1,1,5);

    buttom_layout->addWidget(send_button);
    buttom_layout->addWidget(cancel_button);
    buttom_layout->addStretch();

    main_layout->addLayout(top_layout);
    main_layout->addWidget(msg);
    main_layout->addLayout(buttom_layout);

    connect(send_button,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(cancel_button,SIGNAL(clicked(bool)),this,SLOT(cancel()));
    connect(send_button,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(cancel_button,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void compose_mail::send(){
    qDebug() << "send";
    QString to = to_text->text();
    QString sb = sub_text->text();
    QString m = msg->toPlainText();

    emit send_til_model(to,sb,m);
}

void compose_mail::cancel(){
    qDebug() << "cancel";
}

compose_mail::~compose_mail(){
    qDebug() << "slettet";

}
