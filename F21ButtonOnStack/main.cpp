#include <QApplication>
#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
public:
    Widget(QWidget *parent = 0) : QWidget(parent)
    {
    }
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
// Destroying TestButton!
// The program has unexpectedly finished.
//
// En ser at TestButton ble også slettet, selv om vi bare
// brukte delete på Widget. Men i dette eksempelet blir TestButton slettet to ganger,
// fordi den lå på stack'en, den ble ikke allokert på heap'en med new.
// Når programmet avsluttes og en går ut av main, blir alle variabler på stack'en slettet,
// og det forsøkes da å slette TestButton en andre gang, som ikke lykkes.
// Output over er fra Windows. På Linux kommer ikke programmet så langt engang, det kommer
// til Destroying TestButton! første gangen, og der krasjer det fordi vi prøver delete på en stack variabel.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget;
    TestButton testButton(w);

    testButton.setText("Test button");
    testButton.setGeometry(100,100,75,25);

    w->show();
    a.exec();

    qDebug("Done..");

    return 0;
}
