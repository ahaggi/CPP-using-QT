#include <QApplication>
#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
public:
    Widget(QWidget *parent = 0) : QWidget(parent) { }
    ~Widget()
    {
         qDebug("Destroying Widget!");
    }
};


class TestButton : public QPushButton
{
public:
    TestButton(QWidget *parent = 0)
        : QPushButton(parent)
    {
    }
    ~TestButton() {
        qDebug("Destroying TestButton!");
    }
};


// Eksempel på at en QWidget som er parent sletter alle child widgets
// når den selv sletttes.
// Eksempel på hva som skjer hvis child widget ligger på stack'en.
//
// Output fra programmet (etter en har lukket vinduet):
//
// Destroying Widget!
// Destroying TestButton!
// Done..
//
// En ser at TestButton ble også slettet, selv om vi bare
// brukte delete på Widget.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget;
    TestButton* testButton = new TestButton(w);

    testButton->setText("Test button");
    testButton->setGeometry(100,100,75,25);

    w->show();
    a.exec();

    delete w;

    qDebug("Done..");

    return 0;
}
