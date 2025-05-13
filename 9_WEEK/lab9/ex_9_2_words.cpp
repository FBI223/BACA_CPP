#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <iterator>
#include <cctype>
#include <functional>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;
using namespace chrono;


/**
 * Removes all non alphanumeric characters from given word and converts to lower case.
 * @param[in,out] word on return word consist only of lower case characters.
 */

void toLowerAlpha(std::string &s1) {
    s1.erase(std::remove_if(s1.begin(), s1.end(), [&](char &c) {
        return !(c = std::tolower(c), std::isalpha(c));
    }), s1.end());
}

int main() {
    int count_all = 0;
    int count_distinct = 0;


    std::ifstream filev2("/home/msztu223/CLionProjects/BACA_CPP/9_WEEK/lab9/hamletEN.txt");
    std::istream_iterator<std::string> it(filev2), end;
    std::vector words(it, end);
    std::for_each(words.begin(), words.end(), toLowerAlpha);
    filev2.close();
    printf("\n\n\n");


    std::ifstream file("/home/msztu223/CLionProjects/BACA_CPP/9_WEEK/lab9/hamletEN.txt");
    if (!file) {
        std::cerr << "Cannot open file.\n";
        return 1;
    }

    unordered_map<std::string, int> words_unordered;
    map<std::string, int> words_ordered;
    std::string word;


    auto start_unordered = high_resolution_clock::now();

    while (file >> word) {
        toLowerAlpha(word);
        if (!word.empty())
            ++words_unordered[word];
    }

    auto end_unordered = high_resolution_clock::now();
    auto duration_unordered = duration_cast<milliseconds>(end_unordered - start_unordered);
    std::cout << "unordered_map time: " << duration_unordered.count() << " ms\n";


    file.clear();
    file.seekg(0); // wróć na początek pliku

    auto start_ordered = high_resolution_clock::now();

    while (file >> word) {
        toLowerAlpha(word);
        if (!word.empty())
            ++words_ordered[word];
    }

    auto end_ordered = high_resolution_clock::now();
    auto duration_ordered = duration_cast<milliseconds>(end_ordered - start_ordered);
    std::cout << "map time: " << duration_ordered.count() << " ms\n";


    count_distinct = words_unordered.size();

    cout << "\n\nNumber of distinct words : " << count_distinct << endl;


    std::vector<std::pair<std::string, int> > sorted_words(words_unordered.begin(), words_unordered.end());

    std::sort(sorted_words.begin(), sorted_words.end(), [](const auto &a, const auto &b) {
        return b.second < a.second;
    });

    cout << "\nThe top 20 most popular words: \n";
    for (int i = 0; i < 20 && i < sorted_words.size(); ++i) {
        std::cout << sorted_words[i].first << " : " << sorted_words[i].second << "\n";
    }


    std::multimap<int, std::string, std::greater<> > reverse_map;
    for (const auto &[word, count]: words_ordered) {
        reverse_map.insert({count, word});
    }

    std::cout << "\nThe top 20 most popular words:\n";
    int shown = 0;
    for (const auto &[count, word]: reverse_map) {
        std::cout << word << " : " << count << '\n';
        if (++shown == 20) break;
    }


    return 0;
}

/*
 * Expected output for ./words < hamletEN.txt

Number of distinct words : 4726

The top 20 most popular words:
the : 1145
and : 967
to : 745
of : 673
i : 569
you : 550
a : 536
my : 514
hamlet : 465
in : 437
it : 417
that : 391
is : 340
not : 315
lord : 311
this : 297
his : 296
but : 271
with : 268
for : 248
your : 242

 */
