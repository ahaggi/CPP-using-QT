#include <QInputDialog>
#include <QDir>
#include <QDebug>
#include "listwidget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QSignalMapper>

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent)
{
    outer_hbox_layout = new QHBoxLayout(this);
    button_vbox_layout = new QVBoxLayout();

    buttonAdd = new QPushButton("Add");
    buttonDelete = new QPushButton("Delete");
    buttonClear = new QPushButton("Clear");

    listCities = new QListWidget();

    listCities->addItem("Bergen");
    listCities->addItem("Oslo");
    listCities->addItem("Stockholm");
    listCities->addItem("Copenhagen");

    button_vbox_layout->addWidget(buttonAdd);
    button_vbox_layout->addWidget(buttonDelete);
    button_vbox_layout->addWidget(buttonClear);

    button_vbox_layout->addStretch(); //OBS komenter denne ut og se forskjell når vinduet er maximized
//    button_vbox_layout->addSpacing(100);

    outer_hbox_layout->addWidget(listCities);
    outer_hbox_layout->addLayout(button_vbox_layout);

    connect(buttonDelete, SIGNAL(clicked(bool)),   this,       SLOT(deleteCurrentItem()));
    connect(buttonAdd,    SIGNAL(clicked(bool)),   this,       SLOT(addItem()));
    connect(buttonClear,  SIGNAL(clicked(bool)),   listCities, SLOT(clear()));
    connect(this,         SIGNAL(testSignal(int)), this,       SLOT(testSlot(int)));
}

ListWidget::~ListWidget()
{

}

void ListWidget::addItem(void)
{
// QInputDialog eksempel:
// http://doc.qt.io/qt-4.8/qinputdialog.html#details

    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter the name of a city: "),
                                         tr("City name:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
        listCities->addItem(text);

    emit testSignal(5);
}

void ListWidget::deleteCurrentItem(void)
{
    // http://stackoverflow.com/a/25418363

    qDeleteAll(listCities->selectedItems());
}

void ListWidget::testSlot(int x)
{
    qDebug() << x;
}
