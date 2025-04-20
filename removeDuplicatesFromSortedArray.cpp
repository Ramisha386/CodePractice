#include <iostream>
#include <vector>
using namespace std;

class Solution {  
    public:
        int removeDuplicates(vector<int>& nums) {
            int left=0;
            int right=1;
            if(nums.size()==1)  return 1;
            
            while(right<nums.size())
            {
                while(right<nums.size() && nums[left]>=nums[right])
                {
                    right++;
                }
                if(right==nums.size()) return left+1;
                swap(nums[left+1],nums[right]);
                left++;
                
    
            }
            return left+1;
        
            
        }
    };
    int main()
    {
        vector<int> nums = {1,1};
        Solution sol;
        int k = sol.removeDuplicates(nums);
        for(int i=0;i<k;i++)
        {
            cout<<"number "<<nums[i]<<endl;
        }
        cout<<k<<endl;
        cout << "All tests passed!" << endl;
    }