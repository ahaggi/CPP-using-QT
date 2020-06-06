#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QRadioButton>
#include <QPushButton>

class PrintDialog : public QWidget
{
    Q_OBJECT

private:
    QComboBox *printerChoice;
    QRadioButton *radioBtnLandscape;
    QRadioButton *radioBtnPortrait;
    QRadioButton *radioBtnBlackWhite;
    QRadioButton *radioBtnColor;
    QPushButton *buttonPrint;
    QPushButton *buttonCancel;

public:
    PrintDialog(QWidget *parent = 0);
    ~PrintDialog();

public slots:
    void print(void);
    void cancel(void);
};

#endif // PRINTDIALOG_H
