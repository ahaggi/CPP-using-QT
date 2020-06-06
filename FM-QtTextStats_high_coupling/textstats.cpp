#include <iostream>
#include <sstream>
#include "textstats.h"

void textStats::inputText(std::string text)
{
    const char *letters = "abcdefghijklmnopqrstuvwxyzæøåABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    size_t word_start = 0;
    size_t word_end = 0;
    size_t word_length = 0;

    // Gjør hele teksten om til "lower case" hvis vi skal skille mellom store/små bokstaver
    if(mCaseSensitiveBox->checkState())
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    // Skill ord fra hverandre ved å søke etter tekst som ikke er bokstaver
    // Ordene blir lagret i et map hvor ordet er key, og antall ganger ordet
    // forekommer er value.
    while(word_end != std::string::npos && word_start != std::string::npos){
        word_end = text.find_first_not_of(letters, word_start);

        if(word_end != std::string::npos)
            word_length = word_end - word_start;
        else
            word_length = std::string::npos;

        std::string word = text.substr(word_start, word_length);
        if(word.length() > 0)
            stats[word]++;
        word_start = text.find_first_of(letters, word_end);

        std::cout << "Word found: " << word << std::endl;
    }

    // Vi ønsker å kunne sortere ordene etter hvor ofte de forekommer. Et map
    // lar oss ikke sortere etter value, bare etter key.
    // Hvis vi heller bytter om på hva som er key og value, så kan vi sortere etter
    // hvor ofte ordene forekommer. Men da risikerer vi å ha flere ord med samme frekvens,
    // og dermed flere av samme key i et map. Et vanlig map kan ikke ha flere av samme key,
    // så derfor må vi bruke et multimap istedenfor.
    sorted_stats = flip_map(stats);


    // Oppdater GUI'et her. Her er det demonstrert på en dårlig måte med HØY KOBLING.
    mTextBox->setText(printStats().c_str());

    mTable->clear();
    mTable->setRowCount(0);

    for(auto it = sorted_stats.crbegin(); it != sorted_stats.crend(); it++) {
        // Legg til en ny rad for hvert ord
        mTable->insertRow(mTable->rowCount());

        // Kolonne 0: Frekvens (antall forekomster)
        mTable->setItem(mTable->rowCount()-1,
                                    0,
                                    new QTableWidgetItem(QString::number(it->first)));

        // Kolonne 1: Ord
        mTable->setItem(mTable->rowCount()-1,
                                    1,
                                    new QTableWidgetItem(it->second.c_str()));
    }
}

void textStats::resetStats(void)
{
    stats.clear();
    sorted_stats.clear();
}

std::string textStats::printStats(void)
{

    std::stringstream ss;

    // multimap er sortert med den laveste nøkkelen (key) først, we ønsker å vise
    // de med høyest forekomst (høyest key) først, så derfor må vi iterere bakover
    for(auto it = sorted_stats.crbegin(); it != sorted_stats.crend(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
        ss << it->first << ": " << it->second << std::endl;
    }
    return ss.str();
}
