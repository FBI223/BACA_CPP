#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct TrieNode {
    bool isWord = false;
    unordered_map<char, TrieNode *> children;
};

class Trie {
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {
    }

    void insert(const string &word) {
        TrieNode *node = root;
        for (char c: word) {
            if (!node->children[c])
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool search(const string &word) const {
        TrieNode *node = root;
        for (char c: word) {
            if (!node->children.count(c))
                return false;
            node = node->children.at(c);
        }
        return node->isWord;
    }

    bool startsWith(const string &prefix) const {
        TrieNode *node = root;
        for (char c: prefix) {
            if (!node->children.count(c))
                return false;
            node = node->children.at(c);
        }
        return true;
    }

    ~Trie() {
        clear(root);
    }

private:
    void clear(TrieNode *node) {
        for (auto &[c, child]: node->children)
            clear(child);
        delete node;
    }
};


int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("hell");
    trie.insert("he");

    cout << boolalpha;
    cout << "search(\"hell\") = " << trie.search("hell") << endl; // true
    cout << "search(\"hello\") = " << trie.search("hello") << endl; // true
    cout << "search(\"heaven\") = " << trie.search("heaven") << endl; // false
    cout << "startsWith(\"he\") = " << trie.startsWith("he") << endl; // true
    cout << "startsWith(\"helx\") = " << trie.startsWith("helx") << endl; // false
}

