#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(const string &word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->children.find(ch) == cur->children.end()) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->endOfWord = true;
    }

    bool search(const string &word) {
        return searchHelper(word, root, 0);
    }

private:
    bool searchHelper(const string &word, TrieNode* node, int idx) {
        if (idx == word.size()) {
            return node->endOfWord;
        }

        char ch = word[idx];

        if (ch == '.') {
            // Try all possible children
            for (auto &pair : node->children) {
                TrieNode* child = pair.second;
                if (searchHelper(word, child, idx + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            return searchHelper(word, node->children[ch], idx + 1);
        }
    }
};

int main() {
    WordDictionary dict;

    dict.addWord("cat");
    dict.addWord("cap");
    dict.addWord("dog");
    dict.addWord("can");

    cout << boolalpha; // to print true/false instead of 1/0

    cout << "Search for 'cat': " << dict.search("cat") << endl;     // true
    cout << "Search for 'ca.': " << dict.search("ca.") << endl;     // true (cat, cap, can)
    cout << "Search for 'c.t': " << dict.search("c.t") << endl;     // true (cat)
    cout << "Search for '...': " << dict.search("...") << endl;     // true (cat, cap, dog, can)
    cout << "Search for 'bat': " << dict.search("bat") << endl;     // false
    cout << "Search for 'd.g': " << dict.search("d.g") << endl;     // true (dog)

    return 0;
}
