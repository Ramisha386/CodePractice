#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, subset, result, target);
        return result;
    }

    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& result, int target) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }
        if (i >= nums.size() || target < 0) {
            return;
        }

        // Include nums[i]
        if (target - nums[i] >= 0) {
            subset.push_back(nums[i]);
            dfs(nums, i, subset, result, target - nums[i]);  // Reuse same index
            subset.pop_back();  // Backtrack
        }

        // Skip nums[i]
        dfs(nums, i + 1, subset, result, target);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> combinations = sol.combinationSum(nums, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combo : combinations) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
