#ifndef WIDGET_TEXT_DEMO_H
#define WIDGET_TEXT_DEMO_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class WidgetTextDemo : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* vbox;
    QHBoxLayout* hbox_text;
    QHBoxLayout* hbox_html_text;


    QTextEdit* textEdit;
    QLineEdit* lineEdit;
    QTextEdit* htmlTextEdit;

public:
    WidgetTextDemo(QWidget *parent = 0);
    ~WidgetTextDemo();
};

#endif // WIDGET_TEXT_DEMO_H
