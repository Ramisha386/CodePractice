#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;

    string test1 = "()[]{}";
    string test2 = "([{}])";
    string test3 = "(]";
    string test4 = "((({{{[[[]]]}}})))";
    string test5 = "({[)]}";

    cout << test1 << " -> " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << test2 << " -> " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << test3 << " -> " << (sol.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << test4 << " -> " << (sol.isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << test5 << " -> " << (sol.isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}
