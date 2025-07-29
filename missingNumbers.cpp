#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        // XOR with indices 0..n
        for (int i = 0; i <= n; i++) {
            ans = ans ^ i;
        }
        
        // XOR with actual numbers in nums
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {0, 2};  // missing number should be 1

    cout << "Missing number: " << sol.missingNumber(nums) << endl;

    return 0;
}
