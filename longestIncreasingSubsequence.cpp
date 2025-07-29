#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;  // will track LIS length
        
        for (int x : nums) {
            auto it = lower_bound(ans.begin(), ans.end(), x);
            if (it == ans.end()) {
                ans.push_back(x);  // extend LIS
            } else {
                *it = x;           // replace with smaller value
            }
        }
        return ans.size();
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {9, 1, 4, 3, 32, 3, 7};

    cout << "Length of LIS: " << sol.lengthOfLIS(nums) << endl;

    return 0;
}
