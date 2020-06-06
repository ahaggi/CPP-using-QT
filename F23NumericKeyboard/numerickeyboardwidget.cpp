#include "numerickeyboardwidget.h"

NumericKeyboardWidget::NumericKeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    grid_layout = new QGridLayout(this);

    for(int i = 0; i < 10; i++) { /** Kunne skrevet med nøsted for-løkke*/
        buttons[i] = new QPushButton(QString::number(i));

        // Kode for å bestemme plass i grid layout for knappene basert
        // på knappens verdi.
        if(i == 0)
            grid_layout->addWidget(buttons[0], 4, 1, 1, 1);
        else
            grid_layout->addWidget(buttons[i], 3-((i-1)/3), (i-1)%3, 1, 1);
    }

    numberDisplay = new QLineEdit();
    numberDisplay->setReadOnly(true);
    numberDisplay->setAlignment(Qt::AlignRight);

    buttonClear = new QPushButton("Clear");

    grid_layout->addWidget(numberDisplay, 0, 0, 1, 3);
    grid_layout->addWidget(buttonClear, 4, 2, 1, 1);


    // Bruk av QSignalMapper for å knytte verdier mot knappens nummer
    m = new QSignalMapper();

    for(int i=0; i<10; i++) {
        connect(buttons[i], SIGNAL(clicked(bool)), m, SLOT(map()));
        m->setMapping(buttons[i], i);
    }
    connect(m, SIGNAL(mapped(int)), this, SLOT(keyPressed(int)));
    connect(buttonClear, SIGNAL(clicked(bool)), numberDisplay, SLOT(clear()));
}

NumericKeyboardWidget::~NumericKeyboardWidget()
{

}

void NumericKeyboardWidget::keyPressed(int key_value)
{
        QString current_text = numberDisplay->text();
        QString new_text = current_text + QString::number(key_value);
//        QChar new_text=key_value+97;
        numberDisplay->setText(new_text);
}
