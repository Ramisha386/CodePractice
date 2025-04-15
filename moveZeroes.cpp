#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int* left = &nums[0];
        int* end = &nums[0] + nums.size();
        
      //  cout<<ptr0<<ptr1;
    
        while(left<end)
        {
            if(*left==0)
            {
                 int *right=left+1;
                while(right<end && *right==0)
                {
                    right++;
                }
                if(right>=end)
                    break;
                int temp = *right;
                *right = *left;
                *left= temp;

            }
            left++;
        }      
       
    }
};

int main() {

    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<endl;
   
    return 0;
}
