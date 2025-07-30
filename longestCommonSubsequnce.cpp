#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : set) {
            // Only start counting if 'num' is the start of a sequence
            if (set.find(num - 1) == set.end()) {
                int length = 1;
                while (set.find(num + length) != set.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    
    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    int result = sol.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
