#ifndef WIDGET_COMBO_SLIDER_DEMO_H
#define WIDGET_COMBO_SLIDER_DEMO_H

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QSlider>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class WidgetComboSliderDemo : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* vbox;
    QHBoxLayout* hbox_combo_box;

    QComboBox* comboBox;
    QLineEdit* comboLineEdit;
    QSlider* comboSlider;

public:
    WidgetComboSliderDemo(QWidget *parent = 0);
    ~WidgetComboSliderDemo();
};

#endif // WIDGET_COMBO_SLIDER_DEMO_H
