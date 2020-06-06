
#ifndef COMPOSE_MAIL_H
#define COMPOSE_MAIL_H


#include <QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <vector>

#include <QWidget>

#include<QVBoxLayout>
#include <QGridLayout>

#include<QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QListView>

#include <QDebug>
#include <QSignalMapper>
#include <QInputDialog>

class compose_mail : public QWidget
{
    Q_OBJECT

public:
    compose_mail(QWidget *parent = 0);
    ~compose_mail();
    QGridLayout* top_layout;
    QVBoxLayout* main_layout;
    QHBoxLayout* buttom_layout;

    QLabel* to_label;
    QLabel* sub_label;

    QLineEdit* to_text;
    QLineEdit* sub_text;

    QTextEdit* msg;

    QPushButton* send_button;
    QPushButton* cancel_button;

signals:
    void send_til_model(QString,QString,QString);

public slots:
    void send();
    void cancel();
};

#endif // WIDGET_H
