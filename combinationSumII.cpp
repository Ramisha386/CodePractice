#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, ans, result);
        return result;
    }

    void backtrack(vector<int>& arr, int target, int start, vector<int>& ans, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }

        for (int i = start; i < arr.size(); ++i) {
            // Skip duplicates
            if (i > start && arr[i] == arr[i - 1])
                continue;

            // If current number is bigger than remaining target, break early (since array is sorted)
            if (arr[i] > target)
                break;

            ans.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, ans, result);
            ans.pop_back(); // backtrack
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> results = sol.combinationSum2(candidates, target);

    cout << "Unique combinations summing to " << target << ":\n";
    for (const auto& comb : results) {
        cout << "[ ";
        for (int x : comb) cout << x << " ";
        cout << "]\n";
    }
}
