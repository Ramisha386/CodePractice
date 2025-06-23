#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int curSum = nums[0];
        int maxSum = std::numeric_limits<int>::min();
        int maxi = nums[0];

        for (int i = 1; i < n; i++) {
            curSum = calcSum(curSum, i, nums);
            if (curSum > maxSum) maxSum = curSum;
            if (maxi < nums[i]) maxi = nums[i];
        }

        return maxSum < maxi ? maxi : maxSum;
    }

private:
    int calcSum(int cur, int idx, vector<int>& nums) {
        return (cur + nums[idx] > nums[idx]) ? cur + nums[idx] : nums[idx];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}
