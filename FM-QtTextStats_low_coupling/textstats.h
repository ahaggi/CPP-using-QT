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
    bool mCaseSensitivity;

public:
    textStats(bool case_enable = false) : mCaseSensitivity(case_enable) {}
    void inputText(std::string text);
    void resetStats(void);
    void setCaseSensitivity(bool case_enable) {mCaseSensitivity = case_enable;}
    std::string printStats(void);
    std::multimap<int, std::string>::const_reverse_iterator getStatsIterator(void) const {
        return sorted_stats.crbegin();
    }
    std::multimap<int, std::string>::const_reverse_iterator getStatsEnd(void) const {
        return sorted_stats.crend();
    }
};

#endif // TEXTSTATS_H
