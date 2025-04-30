#include <iostream>
#include <string>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;
        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;

            i++;
        }

        return sign * result;
    }
};

int main() {
    Solution sol;

    // Test cases
    string test1 = "42";
    string test2 = "   -42";
    string test3 = "4193 with words";
    string test4 = "words and 987";
    string test5 = "-91283472332";

    cout << "Input: \"" << test1 << "\" → Output: " << sol.myAtoi(test1) << endl;
    cout << "Input: \"" << test2 << "\" → Output: " << sol.myAtoi(test2) << endl;
    cout << "Input: \"" << test3 << "\" → Output: " << sol.myAtoi(test3) << endl;
    cout << "Input: \"" << test4 << "\" → Output: " << sol.myAtoi(test4) << endl;
    cout << "Input: \"" << test5 << "\" → Output: " << sol.myAtoi(test5) << endl;

    return 0;
}
