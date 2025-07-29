#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int offSet = 1;
        for (int i = 1; i <= n; i++) {
            if (offSet * 2 == i) {
                offSet = i;
            }
            ans[i] = 1 + ans[i - offSet];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = sol.countBits(n);

    cout << "Count of set bits from 0 to " << n << ":\n";
    for (int i = 0; i <= n; i++) {
        cout << "Number: " << i << " -> Bits set: " << result[i] << endl;
    }

    return 0;
}
