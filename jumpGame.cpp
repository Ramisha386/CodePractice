#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        bool flag = goal(nums.size() - 2, nums, nums.size() - 1);
        return flag;
    }

    bool goal(int idx, vector<int>& nums, int parent) {
        if (idx < 0) return false;
        while (nums[idx] < parent - idx) {
            if (idx == 0) return false;
            idx--;
        }
        if (idx == 0 && nums[idx] >= parent - idx) return true;
        else if (idx == 0 && nums[idx] < parent - idx) return false;
        return goal(idx - 1, nums, idx);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "Can jump (nums1): " << (sol.canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump (nums2): " << (sol.canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
