#ifndef TEXTSTATS_H
#define TEXTSTATS_H

#include <string>
#include <map>
#include <algorithm>
#include <QTableWidget>
#include <QTextEdit>
#include <QCheckBox>


// Normal map only allows sorting by key, not by value.
// This function flips, or swaps, the key and value in key/value pairs in a map,
// and puts them in a multimap. Since several keys may have the same value in the
// input map, we need to store the output in a multimap, because a normal map only
// allows unique keys, but the multimap allows for duplicate keys.
// Source: http://stackoverflow.com/a/23050953
template <typename A, typename B>
std::multimap<B, A> flip_map(std::map<A,B> & src) {

    std::multimap<B,A> dst;

    for(auto it = src.begin(); it != src.end(); ++it)
        dst.insert(std::pair<B, A>(it -> second, it -> first));

    return dst;
}

template std::multimap<int, std::string> flip_map(std::map<std::string, int> &);


class textStats {
private:
    std::map<std::string, int> stats;
    std::multimap<int, std::string> sorted_stats;
    QTableWidget* mTable;
    QTextEdit* mTextBox;
    QCheckBox* mCaseSensitiveBox;

public:
    textStats(QTableWidget* table, QTextEdit* textbox, QCheckBox* case_sensitive_checkbox)
        : mTable(table), mTextBox(textbox), mCaseSensitiveBox(case_sensitive_checkbox) {}
    void inputText(std::string text);
    void resetStats(void);
    std::string printStats(void);
};

#endif // TEXTSTATS_H
