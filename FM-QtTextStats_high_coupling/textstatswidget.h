#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "textstats.h"

namespace Ui {
class Widget;
}

class TextStatsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TextStatsWidget(QWidget *parent = 0);
    ~TextStatsWidget();

    // Gjort public så textstats.cpp kan aksessere den
    // (Ikke bra, bare for eksempelet sin del).
    Ui::Widget *ui;

public slots:
    void analyzeText(void);
    void resetTextStats(void);

private:
    //Ui::Widget *ui;
    textStats* mTextStats;
};

#endif // WIDGET_H
