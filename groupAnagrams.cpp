#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>

using namespace std;

class Solution {
public:
    struct ArrayHash {
        size_t operator()(const array<int, 26>& a) const {
            size_t seed = 0;
            hash<int> hasher;
            for (int val : a) {
                seed ^= hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> h1;

        for (const string& s : strs) {
            array<int, 26> V = {0};
            for (char c : s) {
                V[c - 'a']++;
            }
            h1[V].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [key, group] : h1) {
            result.push_back(group);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input = {"cat", "tac", "act", "sit", "tis", "dog", "god"};

    vector<vector<string>> output = solution.groupAnagrams(input);

    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : output) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
