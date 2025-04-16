#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
            if (nums[i] == val){
                swap(nums[j], nums[i]);
                j -= 1;}
            else
                i += 1 ; 

        return j + 1;
            
        }
    };

    int main()
    {
        vector<int> nums = {3,2,2,3};
        Solution sol;
        int k = sol.removeElement(nums,3);
        for(int i=0;i<k;i++)
        {
            cout<<"number "<<nums[i]<<endl;
        }
        cout<<k<<endl;
        cout << "All tests passed!" << endl;
    }