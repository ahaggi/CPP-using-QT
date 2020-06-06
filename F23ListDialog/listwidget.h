#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class ListWidget : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout* button_vbox_layout;
    QHBoxLayout* outer_hbox_layout;

    QPushButton* buttonAdd;
    QPushButton* buttonDelete;
    QPushButton* buttonClear;

    QListWidget* listCities;

public:
    ListWidget(QWidget *parent = 0);
    ~ListWidget();

signals:
    void testSignal(int);

public slots:
    void addItem(void);
    void deleteCurrentItem(void);
    void testSlot(int);
};

#endif // LISTWIDGET_H
