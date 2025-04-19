#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result;

        // Fill result with squares in reverse order (from largest to smallest)
        while (left <= right) {
            if (abs(nums[left]) >= abs(nums[right])) {
                result.push_back(nums[left] * nums[left]);
                left++;
            } else {
                result.push_back(nums[right] * nums[right]);
                right--;
            }
        }

        // Reverse the result to get sorted order
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {-7, -3, 2, 3, 11};

    vector<int> result = sol.sortedSquares(nums);

    cout << "Sorted squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
