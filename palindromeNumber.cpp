#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        string s = to_string(x);
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (solution.isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
