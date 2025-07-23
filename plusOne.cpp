#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;

        for (int i = n; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1); // Handles cases like 999 + 1 = 1000
        return digits;
    }
};

int main() {
    // Example input
    vector<int> digits = {6, 7, 9};

    Solution sol;
    vector<int> result = sol.plusOne(digits);

    // Output the result
    cout << "Result: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
