#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->children.find(ch) == cur->children.end()) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->children.find(ch) == cur->children.end()) {
                return false;
            }
            cur = cur->children[ch];
        }
        return cur->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char ch : prefix) {
            if (cur->children.find(ch) == cur->children.end()) {
                return false;
            }
            cur = cur->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    
    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Test search
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << endl;
    cout << "Search 'appl': " << (trie.search("appl") ? "Found" : "Not found") << endl;

    // Test startsWith
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "Yes" : "No") << endl;
    cout << "Starts with 'bat': " << (trie.startsWith("bat") ? "Yes" : "No") << endl;

    return 0;
}
