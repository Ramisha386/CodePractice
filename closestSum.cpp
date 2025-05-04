#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int currSum = nums[i] + nums[l] + nums[r];

                if (abs(target - currSum) < abs(target - closestSum))
                    closestSum = currSum;

                if (currSum < target)
                    l++;
                else if (currSum > target)
                    r--;
                else
                    return currSum; // exact match found
            }
        }

        return closestSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 1};
    int target = 0;

    int result = sol.threeSumClosest(nums, target);

    cout << "Closest sum to " << target << " is: " << result << endl;

    return 0;
}
