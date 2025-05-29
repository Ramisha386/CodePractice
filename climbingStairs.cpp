#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr(n + 1, 0);
        arr[0] = 1;
        arr[1] = 1;
        if (n == 1) return 1;
        arr[n] = climb(n - 1, arr) + climb(n - 2, arr);
        return arr[n];
    }

    int climb(int n, vector<int>& arr) {
        if (n <= 0) return 1;
        if (arr[n] != 0) return arr[n];
        arr[n] = climb(n - 1, arr) + climb(n - 2, arr);
        return arr[n];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of stairs cannot be negative." << endl;
        return 1;
    }

    int ways = solution.climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}
