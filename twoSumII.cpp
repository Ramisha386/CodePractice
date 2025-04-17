#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
           
            int p1=0;
            int p2=numbers.size()-1;
            
           
            while(p1<p2)
            {
                int sum=numbers[p1]+numbers[p2];
                //cout<<"sum"<<sum<<endl;
                if(sum==target)
                {
                    return {p1+1,p2+1};
                }
                else if(target-numbers[p1]<numbers[p2]) p2--;
                else p1++;
    
                
            }
            return {};
            
        }
    };

int main() {
    Solution sol;
    vector<int> numbers = {-3,3,4,90}; // Example input
    int target = 0;

    vector<int> result = sol.twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
