#include <QDebug>
#include "printdialog.h"
#include "ui_printdialog.h"

PrintDialog::PrintDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintDialog)
{
    ui->setupUi(this);

    connect(ui->buttonPrint, SIGNAL(clicked(bool)), this, SLOT(print()));
    connect(ui->buttonCancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}

PrintDialog::~PrintDialog()
{
    delete ui;
}

void PrintDialog::print(void)
{
    QString printer_choice;
    QString orientation_choice;
    QString color_choice;

    printer_choice = ui->printerChoice->currentText();

    if(ui->radioBtnLandscape->isChecked())
        orientation_choice = "landscape";
    else
        orientation_choice = "portrait";

    if(ui->radioBtnColor->isChecked())
        color_choice = "color";
    else
        color_choice = "black and white";

    qDebug("Printing in %s with %s orientation, on printer %s.",
           color_choice.toStdString().c_str(),
           orientation_choice.toStdString().c_str(),
           printer_choice.toStdString().c_str());

    this->close();
}

void PrintDialog::cancel(void)
{
    qDebug() << "Print cancelled.";
    this->close();
}
