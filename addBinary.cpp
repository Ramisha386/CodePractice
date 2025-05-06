#include <iostream>
#include <string>
#include <algorithm>  // for reverse

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            carry = sum > 1 ? 1 : 0;
            result += (sum % 2) + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string a, b;

    // Example usage
    cout << "Enter first binary string: ";
    cin >> a;
    cout << "Enter second binary string: ";
    cin >> b;

    string sum = sol.addBinary(a, b);
    cout << "Sum: " << sum << endl;

    return 0;
}
