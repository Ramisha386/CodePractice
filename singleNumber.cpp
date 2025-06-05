#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main() {
    // Example input: all numbers appear twice except one
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution sol;
    int result = sol.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}
