#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int left=0;
        int right=height.size()-1;
        int area;
       
        while(left<right)
        {
            area=min(height[left],height[right])*(right-left);
         //   cout<<"Area "<<area<<endl;
            maxArea=max(maxArea,area);
            if(height[left]<height[right])
                left++;
            else
                right--;


        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int result = sol.maxArea(heights);
    cout << "Maximum area: " << result << endl;
    return 0;
}
