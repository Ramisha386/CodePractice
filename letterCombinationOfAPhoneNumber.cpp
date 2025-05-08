#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string &digits, int index, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result);
            current.pop_back();  // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter digits (2-9): ";
    cin >> input;

    vector<string> combinations = sol.letterCombinations(input);

    cout << "Letter combinations:" << endl;
    for (const string &s : combinations) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
