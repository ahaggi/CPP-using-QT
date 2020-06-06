#include "widget_combo_slider_demo.h"

WidgetComboSliderDemo::WidgetComboSliderDemo(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    hbox_combo_box = new QHBoxLayout();

    comboBox = new QComboBox();
    comboLineEdit = new QLineEdit();
    comboSlider = new QSlider();

    hbox_combo_box->addWidget(comboBox);
    hbox_combo_box->addWidget(comboLineEdit);
    hbox_combo_box->addWidget(comboSlider);

    vbox->addWidget(new QLabel("Legg til noen valg i comboBox, få lineEdit til å vise valgt item, og gjør slideren horisontal og få den til å styre valg i comboBox."));
    vbox->addLayout(hbox_combo_box);
    vbox->addStretch();

    // Her er noen forslag på gode valg en kan ha i comboBox'en.
    comboBox->addItem("Pizza");
    comboBox->addItem("Brus");
    comboBox->addItem("Kake");
    comboBox->addItem("Kebab");
    comboBox->addItem("Sjokolade");

    comboLineEdit->setText(comboBox->currentText());
    comboSlider->setRange(0, comboBox->count()-1);
    comboSlider->setValue(0);

    connect(comboBox, SIGNAL(currentIndexChanged(QString)), comboLineEdit, SLOT(setText(QString)));
    connect(comboBox, SIGNAL(currentIndexChanged(int)), comboSlider, SLOT(setValue(int)));
    connect(comboSlider, SIGNAL(valueChanged(int)), comboBox, SLOT(setCurrentIndex(int)));
}

WidgetComboSliderDemo::~WidgetComboSliderDemo()
{

}
