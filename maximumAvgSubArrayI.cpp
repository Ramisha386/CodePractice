#include <iostream>
#include <vector>
#include <algorithm> // for max
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int n = nums.size();

        // Initial sum of first k elements
        for (int i = 0; i < k; i++)
            sum += nums[i];

        double maxSum = sum;

        // Sliding window
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};

int main() {
    int k = 4;
    vector<int> nums = {1,12,-5,-6,50,3};
    Solution sol;
    double result = sol.findMaxAverage(nums, k);

    cout.precision(10); // More precision to match expected result exactly
    cout << "Max average of subarray of size " << k << " is: " << result << endl;

    return 0;
}