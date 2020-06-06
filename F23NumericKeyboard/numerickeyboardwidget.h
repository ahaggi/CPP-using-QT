#ifndef NUMERICKEYBOARDWIDGET_H
#define NUMERICKEYBOARDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QSignalMapper>

class NumericKeyboardWidget : public QWidget
{
    Q_OBJECT

private:
    QGridLayout* grid_layout;
    QPushButton* buttons[10];
    QPushButton* buttonClear;
    QLineEdit* numberDisplay;
    QSignalMapper* m;

public:
    NumericKeyboardWidget(QWidget *parent = 0);
    ~NumericKeyboardWidget();

public slots:
    void keyPressed(int key_value);
};

#endif // NUMERICKEYBOARDWIDGET_H
