#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        int l, r, len, start, end;
        int maxLength = 1;
        
        for (int i = 0; i < n - 1; i++) {
            l = i;
            r = i;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    l--;
                    r++;
                } else break;
            }
            
            len = r - l - 1;
            if (maxLength < len) {
                maxLength = len;
                start = l + 1;
                end = r - 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            l = i;
            r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    l--;
                    r++;
                } else break;
            }
            
            len = r - l - 1;
            if (maxLength < len) {
                maxLength = len;
                start = l + 1;
                end = r - 1;
            }
        }
        
        return s.substr(start, maxLength);
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    cin >> input;
    
    string result = sol.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;
    
    return 0;
}
