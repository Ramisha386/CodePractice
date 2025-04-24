#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                ++left;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
