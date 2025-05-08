#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;

                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1000000000, -1000000000, -1000000000, -1000000000};
    int target = -1;

    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << ":\n";
    for (const auto& quad : result) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); ++i) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
