#include <QLabel>
#include "widget_button_demo.h"

WidgetButtonDemo::WidgetButtonDemo(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    hbox_buttons = new QHBoxLayout();
    hbox_radios1 = new QHBoxLayout();
    hbox_radios2 = new QHBoxLayout();
    hbox_radios3 = new QHBoxLayout();
    hbox_radios3_text = new QHBoxLayout();

    normalButton = new QPushButton("Normal Button");
    disabledButton = new QPushButton("Disabled Button");
    hiddenButton = new QPushButton("Hidden Button");
    checkableButton = new QPushButton("Checkable Button");
    hotKeyButton = new QPushButton("H&otkey Button");
    iconButton = new QPushButton("Icon Button");

    rbutton1 = new QRadioButton("Option A1");
    rbutton2 = new QRadioButton("Option A2");
    rbutton3 = new QRadioButton("Option A3");
    rbutton4 = new QRadioButton("Option B1");
    rbutton5 = new QRadioButton("Option B2");
    rbutton6 = new QRadioButton("Option B3");

    rbutton7 = new QRadioButton("Option C1");
    rbutton8 = new QRadioButton("Option C2");
    rbutton9 = new QRadioButton("Option C3");
    rbutton10 = new QRadioButton("Option D1");
    rbutton11 = new QRadioButton("Option D2");
    rbutton12 = new QRadioButton("Option D3");

    groupButtons = new QGroupBox("Forsøk å gi knappene under oppførsel som stemmer med beskrivelsen. Bruk play-icon.ico som ikon.");
    groupRadioButtons1 = new QGroupBox("Radio buttons A");
    groupRadioButtons2 = new QGroupBox("Radio buttons B");

    buttonGroupC = new QButtonGroup();
    buttonGroupD = new QButtonGroup();

    hbox_buttons->addWidget(normalButton);
    hbox_buttons->addWidget(disabledButton);
    hbox_buttons->addWidget(hiddenButton);
    hbox_buttons->addWidget(checkableButton);
    hbox_buttons->addWidget(hotKeyButton);
    hbox_buttons->addWidget(iconButton);

    groupButtons->setLayout(hbox_buttons);

    hbox_radios1->addWidget(rbutton1);
    hbox_radios1->addWidget(rbutton2);
    hbox_radios1->addWidget(rbutton3);
    hbox_radios2->addWidget(rbutton4);
    hbox_radios2->addWidget(rbutton5);
    hbox_radios2->addWidget(rbutton6);

    groupRadioButtons1->setLayout(hbox_radios1);
    groupRadioButtons2->setLayout(hbox_radios2);

    hbox_radios3_text->addSpacing(50);
    hbox_radios3_text->addWidget(new QLabel("Button Group C"));
    hbox_radios3_text->addStretch();
    hbox_radios3_text->addWidget(new QLabel("Button Group D"));
    hbox_radios3_text->addSpacing(50);

    hbox_radios3->addWidget(rbutton7);
    hbox_radios3->addWidget(rbutton8);
    hbox_radios3->addWidget(rbutton9);
    hbox_radios3->addWidget(rbutton10);
    hbox_radios3->addWidget(rbutton11);
    hbox_radios3->addWidget(rbutton12);

    buttonGroupC->addButton(rbutton7);
    buttonGroupC->addButton(rbutton8);
    buttonGroupC->addButton(rbutton9);

    buttonGroupD->addButton(rbutton10);
    buttonGroupD->addButton(rbutton11);
    buttonGroupD->addButton(rbutton12);



    //---------------------------------------------------------------------------
    // Sett inn kode for å gi buttons riktig oppførsel her
    disabledButton->setDisabled(true);
    hiddenButton->setVisible(false);
    checkableButton->setCheckable(true);
    iconButton->setIcon(QIcon("/home/haji/Desktop/QT/F23Widgets_test_layout/play-icon.ico"));

    vbox->addWidget(groupButtons);
    vbox->addSpacing(50);
    vbox->addWidget(groupRadioButtons1);
    vbox->addSpacing(50);
    vbox->addWidget(groupRadioButtons2);
    vbox->addSpacing(50);
    vbox->addLayout(hbox_radios3_text);
    vbox->addLayout(hbox_radios3);
}

WidgetButtonDemo::~WidgetButtonDemo()
{

}
