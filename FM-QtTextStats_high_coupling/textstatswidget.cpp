#include "textstatswidget.h"
#include "ui_widget.h"

TextStatsWidget::TextStatsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mTextStats = new textStats(ui->textStatsTable, ui->textStatsOutput, ui->case_sensitive_checkBox);

    connect(ui->analyzeButton, SIGNAL(clicked(bool)), this, SLOT(analyzeText()));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(resetTextStats()));
}

TextStatsWidget::~TextStatsWidget()
{
    delete ui;
}

void TextStatsWidget::analyzeText(void)
{
    // Send tekst input til textstats klassen,
    // og be den om å oppdatere GUI elementene i denne klassen/widgeten
    mTextStats->inputText(ui->textEdit->toPlainText().toStdString());
}

void TextStatsWidget::resetTextStats(void)
{
    mTextStats->resetStats();
    ui->textStatsOutput->clear();
    ui->textStatsTable->setRowCount(0);
}
