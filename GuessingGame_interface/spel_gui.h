#ifndef SPEL_GUI_H
#define SPEL_GUI_H

#include<dialog.h>
#include<spel.h>
#include <QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <vector>
#include"spel_grense.h"


class spel_gui : public QWidget
{
    Q_OBJECT

public:
    spel_gui(QWidget *parent = 0);
    QHBoxLayout *hbox;
    vector<QPushButton*> buttons;

    QSignalMapper *mapper;
    spel_grense * sp;

    dialog wd;
    ~spel_gui();

public slots:
    void proev(int verdi);
    void startPaaNytt();

};


#endif // SPEL_GUI_H
