#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string input = "Hello World  ";
    int result = sol.lengthOfLastWord(input);
    cout << "Length of the last word: " << result << endl;
    return 0;
}
