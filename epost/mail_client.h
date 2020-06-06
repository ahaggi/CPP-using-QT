#ifndef MAIL_CLIENT_H
#define MAIL_CLIENT_H


#include "compose_mail.h"

#include <QWidget>

#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QGridLayout>

#include<QPushButton>
#include <QLineEdit>
#include <QListView>

#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>

#include"listmodel.h"

class mail_client : public QWidget
{
    Q_OBJECT

public:
    mail_client(QWidget *parent = 0);
    ~mail_client();
    QHBoxLayout* main_layout;
    QVBoxLayout* right_layout;
    QPushButton* check_button;
    QPushButton* del_button;
    QPushButton* new_button;
    QListView* list_view;
    list_model * model;


public slots:
    void check();
    void del();
    void ny();

};

#endif // WIDGET_H
