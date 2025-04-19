#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        string result;

        // Step 1: Split the sentence into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Reverse each word and append to result
        for (size_t i = 0; i < words.size(); ++i) {
            reverse(words[i].begin(), words[i].end());
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input);  // allows input with spaces

    string output = sol.reverseWords(input);

    cout << "Reversed words: " << output << endl;

    return 0;
}
