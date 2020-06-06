#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QWidget>

namespace Ui {
class PrintDialog;
}

class PrintDialog : public QWidget
{
    Q_OBJECT

public:
    explicit PrintDialog(QWidget *parent = 0);
    ~PrintDialog();

public slots:
    void print(void);
    void cancel(void);

private:
    Ui::PrintDialog *ui;
};

#endif // PRINTDIALOG_H
