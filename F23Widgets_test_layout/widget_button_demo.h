#ifndef WIDGET_BUTTON_DEMO_H
#define WIDGET_BUTTON_DEMO_H

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class WidgetButtonDemo : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* vbox;
    QHBoxLayout* hbox_buttons;
    QHBoxLayout* hbox_radios1;
    QHBoxLayout* hbox_radios2;
    QHBoxLayout* hbox_radios3;
    QHBoxLayout* hbox_radios3_text;

    QGroupBox* groupButtons;
    QGroupBox* groupRadioButtons1;
    QGroupBox* groupRadioButtons2;

    QPushButton* normalButton;
    QPushButton* disabledButton;
    QPushButton* hiddenButton;
    QPushButton* checkableButton;
    QPushButton* hotKeyButton;
    QPushButton* iconButton;

    QRadioButton* rbutton1;
    QRadioButton* rbutton2;
    QRadioButton* rbutton3;
    QRadioButton* rbutton4;
    QRadioButton* rbutton5;
    QRadioButton* rbutton6;
    QRadioButton* rbutton7;
    QRadioButton* rbutton8;
    QRadioButton* rbutton9;
    QRadioButton* rbutton10;
    QRadioButton* rbutton11;
    QRadioButton* rbutton12;

    QButtonGroup* buttonGroupC;
    QButtonGroup* buttonGroupD;

public:
    WidgetButtonDemo(QWidget *parent = 0);
    ~WidgetButtonDemo();
};

#endif // WIDGET_BUTTON_DEMO_H
