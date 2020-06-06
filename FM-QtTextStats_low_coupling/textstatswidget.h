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

public slots:
    void analyzeText(void);
    void resetTextStats(void);
    void updateCaseSensitivity(bool case_sensitivity_enable);

private:
    textStats* mTextStats;
    Ui::Widget *ui;
};

#endif // WIDGET_H
