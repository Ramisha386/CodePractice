#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int k = nums.size() - 1;
        int count = 0;
        while (k >= 0) {
            int j = k - 1;
            while (j >= 0) {
                if (nums[k] - nums[j] == diff && j - 1 >= 0) {
                    int i = j - 1;
                    while (i >= 0) {
                        if (nums[j] - nums[i] == diff) {
                            count++;
                        }
                        i--;
                    }
                }
                j--;
            }
            k--;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Sample test case
    vector<int> nums = {0, 1, 4, 6, 7, 10}; // example input
    int diff = 3;

    int result = sol.arithmeticTriplets(nums, diff);
    cout << "Number of arithmetic triplets: " << result << endl;

    return 0;
}
