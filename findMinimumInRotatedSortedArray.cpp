#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int minVal = INT_MAX;  // safer than hardcoding 10000
        bool rotate;

        if (nums[0] > nums[r]) { // rotated case
            while (l <= r) {
                int mid = l + (r - l) / 2;
                minVal = min(minVal, nums[mid]);

                if (nums[mid] < nums[r])
                    rotate = false;
                else
                    rotate = true;

                if (rotate == false)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        } else {
            return nums[0]; // already sorted, no rotation
        }
        return minVal;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    
    cout << "Minimum element in rotated sorted array: " 
         << sol.findMin(nums) << endl;

    return 0;
}
