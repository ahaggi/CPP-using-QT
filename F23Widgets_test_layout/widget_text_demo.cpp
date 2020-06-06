#include "widget_text_demo.h"

WidgetTextDemo::WidgetTextDemo(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    hbox_text = new QHBoxLayout();
    hbox_html_text = new QHBoxLayout();

    textEdit = new QTextEdit();
    lineEdit = new QLineEdit();
    textEdit->setText("textEdit\ntillater\ntekst\nover\nflere\nlinjer");
    lineEdit->setText("Det\ngjør\nikke\nlineEdit");
    hbox_text->addWidget(textEdit);
    hbox_text->addWidget(lineEdit);

    htmlTextEdit = new QTextEdit();
    htmlTextEdit->setText("<!DOCTYPE html>\n"
                          "<html>\n"
                          "<body>\n"
                          "<p>I am normal</p>\n"
                          "<p style=\"color:red;\">I am red</p>\n"
                          "<p style=\"color:blue;\">I am blue</p>\n"
                          "<p style=\"font-size:36px;\">I am big</p>\n"
                          "<img src=\"/home/haji/Desktop/QT/F23Widgets_test_layout/w3schools.jpg\" alt=\"W3Schools.com\" width=\"104\" height=\"142\">\n"
                          "</body>\n"
                          "</html>\n");

    hbox_html_text->addWidget(htmlTextEdit);


    vbox->addLayout(hbox_text);
    vbox->addSpacing(50);
    vbox->addWidget(new QLabel("textEdit med HTML kode: "));
    vbox->addWidget(htmlTextEdit);
    vbox->addSpacing(50);
}

WidgetTextDemo::~WidgetTextDemo()
{

}
