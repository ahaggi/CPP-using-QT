#include "textstatswidget.h"
#include "ui_widget.h"

TextStatsWidget::TextStatsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mTextStats = new textStats();

    connect(ui->analyzeButton, SIGNAL(clicked(bool)), this, SLOT(analyzeText()));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this, SLOT(resetTextStats()));
    connect(ui->case_sensitive_checkBox, SIGNAL(clicked(bool)), this, SLOT(updateCaseSensitivity(bool)));
}

TextStatsWidget::~TextStatsWidget()
{
    delete ui;
}

void TextStatsWidget::analyzeText(void)
{
    // Send tekst input til textstats klassen
    mTextStats->inputText(ui->textEdit->toPlainText().toStdString());

    // Oppdater GUI'et her. Her er det demonstrert på en bedre måte med lavere kobling,
    // for selve klassen som analyserer teksten har ingen kobling til GUI elementene
    ui->textStatsOutput->setText(mTextStats->printStats().c_str());

    ui->textStatsTable->clear();
    ui->textStatsTable->setRowCount(0);

    for(auto it = mTextStats->getStatsIterator(); it != mTextStats->getStatsEnd(); it++) {
        // Legg til en ny rad for hvert ord
        ui->textStatsTable->insertRow(ui->textStatsTable->rowCount());

        // Kolonne 0: Frekvens (antall forekomster)
        ui->textStatsTable->setItem(ui->textStatsTable->rowCount()-1,
                                    0,
                                    new QTableWidgetItem(QString::number(it->first)));

        // Kolonne 1: Ord
        ui->textStatsTable->setItem(ui->textStatsTable->rowCount()-1,
                                    1,
                                    new QTableWidgetItem(it->second.c_str()));
    }
}

void TextStatsWidget::resetTextStats(void)
{
    mTextStats->resetStats();
    ui->textStatsOutput->clear();
    ui->textStatsTable->setRowCount(0);
}

void TextStatsWidget::updateCaseSensitivity(bool case_sensitivity_enable)
{
    mTextStats->setCaseSensitivity(case_sensitivity_enable);
}
