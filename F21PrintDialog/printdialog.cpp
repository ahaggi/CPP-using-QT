#include <QLabel>
#include <QDebug>
#include "printdialog.h"

//  Layout for print dialogen:
//
//  +------------------------------------------------------------+
//  |                     outerLayout (VBox)                     |
//  |             (top-level layout for PrintDialog)             |
//  |                                                            |
//  |  +------------------------------------------------------+  |
//  |  |          topLayout (HBox, for printer choice)        |  |
//  |  +------------------------------------------------------+  |
//  |  +------------------------------------------------------+  |
//  |  |                  groupLayout  (HBox)                 |  |
//  |  |                                                      |  |
//  |  | +--------------------------+ +---------------------+ |  |
//  |  | | orientationLayout (VBox) | | colorLayout (VBox)  | |  |
//  |  | |    (orientationGroup)    | | (colorGroup)        | |  |
//  |  | +--------------------------+ +---------------------+ |  |
//  |  +------------------------------------------------------+  |
//  |  +------------------------------------------------------+  |
//  |  |     buttonLayout (HBox, Print and Cancel button      |  |
//  |  +------------------------------------------------------+  |
//  |                                                            |
//  +------------------------------------------------------------+

PrintDialog::PrintDialog(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();

    printerChoice = new QComboBox();
    radioBtnPortrait = new QRadioButton("Portrait");
    radioBtnLandscape = new QRadioButton("Landscape");
    radioBtnColor = new QRadioButton("Color");
    radioBtnBlackWhite = new QRadioButton("Black and white");
    buttonPrint = new QPushButton("Print");
    buttonCancel = new QPushButton("Cancel");

    printerChoice->addItem("Canon InkWaster XYZ3000");
    printerChoice->addItem("Sister PrintMaster 800");
    printerChoice->addItem("HP PaperJammer B200");

    radioBtnLandscape->setChecked(true);
    radioBtnBlackWhite->setChecked(true);


    // Layout of the printer choice layout at the top
    // ----------------------------------------------
    topLayout->addWidget(new QLabel("Printer:"));
    topLayout->addWidget(printerChoice);
    outerLayout->addLayout(topLayout);


    // Layout of the orientation and color groups
    // ----------------------------------------------
    QHBoxLayout *groupLayout = new QHBoxLayout();

    QGroupBox *orientationGroup = new QGroupBox("Page Orientation");
    QVBoxLayout *orientationLayout = new QVBoxLayout(orientationGroup);   // orientationLayout is layout for orientationGroup
    orientationLayout->addWidget(radioBtnLandscape);
    orientationLayout->addWidget(radioBtnPortrait);
    groupLayout->addWidget(orientationGroup);

    QGroupBox *colorGroup = new QGroupBox("Color Options");
    QVBoxLayout *colorLayout = new QVBoxLayout(colorGroup);    // colorLayout is layout for colorGroup
    colorLayout->addWidget(radioBtnBlackWhite);
    colorLayout->addWidget(radioBtnColor);
    groupLayout->addWidget(colorGroup);

    outerLayout->addLayout(groupLayout);
    outerLayout->addStretch();

    // Bottom layout of Print and Cancel button
    // ----------------------------------------------
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(buttonPrint);
    buttonLayout->addWidget(buttonCancel);
    outerLayout->addLayout(buttonLayout);


    connect(buttonPrint, SIGNAL(clicked(bool)), this, SLOT(print()));
    connect(buttonCancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
}

PrintDialog::~PrintDialog()
{

}

void PrintDialog::print(void)
{
    QString printer_choice;
    QString orientation_choice;
    QString color_choice;

    printer_choice = printerChoice->currentText();

    if(radioBtnLandscape->isChecked())
        orientation_choice = "landscape";
    else
        orientation_choice = "portrait";

    if(radioBtnColor->isChecked())
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

