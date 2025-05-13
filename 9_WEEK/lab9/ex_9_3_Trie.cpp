#include <iostream>
#include <fstream>
#include <vector>
#include <map>


using namespace std;
/**
 * Trie structure
 *
 * HINT: use std::map to implement it!
 *       My implementation adds less than 25 lines of code. 
 */


class TrieNode {
public:
    bool isEnd = false;
    map<string, TrieNode *> children;
};

class Trie {
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {
    }

    static void printSentence(const std::vector<std::string> &sentence) {
        for (const auto &w: sentence)
            cout << w << " ";
    }


    void add(const vector<string> &sentence) {
        cout << "Adding : ";
        printSentence(sentence);
        cout << "\n";

        TrieNode *node = root;

        for (const string &str: sentence) {
            if (!node->children[str])
                node->children[str] = new TrieNode();
            node = node->children[str];
        }
        node->isEnd = true;
    }


    void printPossibleEndings(const std::vector<std::string> &beginningOfSentece) {
        cout << "Endings for \"";
        printSentence(beginningOfSentece);
        cout << "\" are :\n";


        TrieNode *node = root;

        // szukamy konca prefixu w drzewie
        for (const string &word: beginningOfSentece) {
            if (!node->children.count(word)) {
                cout << " > (no continuation)\n";
                return;
            }
            node = node->children[word];
        }

        // startujemy dfs od niego od tego wezla konca prefixu podanego zdania
        vector<string> current;
        dfs(node, current);
    }


    void dfs(TrieNode *node, vector<string> &path) {
        if (node->isEnd) {
            cout << " >";
            for (const string &word: path)
                cout << " " << word;
            cout << "\n";
        }

        for (const auto &[word, child]: node->children) {
            path.push_back(word);
            dfs(child, path);
            path.pop_back();
        }
    }


    void load(const std::string &fileName) {
        ifstream file(fileName);
        if (!file) {
            cerr << "Error when openning file " << fileName << endl;
            return;
        }
        string word;
        vector<string> sentence;
        while (file >> word) {
            sentence.push_back(word);
            // is it end of the sentence?
            if (word.find_last_of('.') != string::npos) {
                add(sentence);
                sentence.clear();
            }
        }
    }


    ~Trie() {
        clear(root);
    }

private:
    void clear(TrieNode *node) {
        for (auto &[_, child]: node->children)
            clear(child);
        delete node;
    }
};


int main() {
    Trie dictionary;
    dictionary.load("/home/msztu223/CLionProjects/BACA_CPP/9_WEEK/lab9/sample.txt");
    //dictionary.load("hamletEN.txt");

    dictionary.printPossibleEndings({"Curiosity"});
    dictionary.printPossibleEndings({"Curiosity", "killed"});
    dictionary.printPossibleEndings({"The", "mouse", "was", "killed"});

    /* cout << "Beginning of sentence (ended with single .): ";
    string word;
    vector<string> sentence;
    while(true){
        cin >> word;
        if(word == ".")
            break;
        sentence.push_back(word);
        dictionary.printPossibleEndings(sentence);
    }*/
    return 0;
}

/* Expected output:
Adding : Curiosity killed the cat.
Adding : Curiosity killed the mouse.
Adding : Curiosity saved the cat.
Adding : Curiosity killed the cat and the mouse.
Adding : The cat was killed by curiosity.
Adding : The mouse was killed by cat.
Adding : The mouse was killed by curiosity.
Endings for "Curiosity " are :
 > killed the cat.
 > killed the mouse.
 > killed the cat and the mouse.
 > saved the cat.

Endings for "Curiosity killed " are :
 > killed the cat.
 > killed the mouse.
 > killed the cat and the mouse.

Endings for "The mouse was killed " are :
 > by cat.
 > by curiosity.

 */
