#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include <QWidget>
#include <QDial>
#include <QHBoxLayout>
#include <QVBoxLayout>

class DialWidget : public QWidget
{
    Q_OBJECT

    QDial* dial1;
    QDial* dial2;

    QHBoxLayout* hbox;
    QVBoxLayout* vbox;

public:
    DialWidget(QWidget *parent = 0);
    ~DialWidget();

public slots:
    void printDial1Value(int value);
};

#endif // DIALWIDGET_H
