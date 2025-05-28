#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }

    void backtrack(string s, int open, int close, int n, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        if (open < n)
            backtrack(s + "(", open + 1, close, n, result);

        if (close < open)
            backtrack(s + ")", open, close + 1, n, result);
    }
};

int main() {
    int n = 3;  // You can change this value to test with other numbers of pairs
    Solution solution;
    vector<string> parentheses = solution.generateParenthesis(n);

    cout << "All valid combinations of " << n << " pairs of parentheses:\n";
    for (const string& s : parentheses) {
        cout << s << endl;
    }

    return 0;
}
