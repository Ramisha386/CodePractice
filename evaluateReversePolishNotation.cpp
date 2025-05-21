#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        int i = 0;
        while (i < n) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                if (tokens[i] == "+") {
                    st.push(y + x);
                } else if (tokens[i] == "*") {
                    st.push(y * x);
                } else if (tokens[i] == "-") {
                    st.push(y - x);
                } else {
                    st.push(y / x);
                }
            }
            i++;
        }
        return st.top();
    }
};

int main() {
    Solution sol;

    // Example: Reverse Polish Notation for (2 + 1) * 3 => should return 9
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    int result = sol.evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
