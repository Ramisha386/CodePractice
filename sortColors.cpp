#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int fr0 = 0, fr1 = 0, fr2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) fr0++;
            else if(nums[i] == 1) fr1++;
            else fr2++;
        }
        int i = 0;
        while(fr0--) nums[i++] = 0;
        while(fr1--) nums[i++] = 1;
        while(fr2--) nums[i++] = 2;
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution solution;
    solution.sortColors(nums);

    cout << "Sorted colors: ";
    for(int i=0;i<nums.size();i++) {
        cout << nums[i]<< " ";
    }

    return 0;
}