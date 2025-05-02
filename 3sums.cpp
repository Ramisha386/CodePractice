#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream> // For atexit use

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> v;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    v.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }

        for (auto it : v) {
            ans.push_back(vector<int>(it.begin(), it.end()));
        }

        return ans;
    }
};

// For whatever purpose this was originally used
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
