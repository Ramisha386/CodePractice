#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string small, string big) {
        int count=0;
        int smallsize=small.size();
        int bigsize=big.size();
        int i=0;
        int j=0;
        
            while(i<smallsize && j<bigsize)
            {
              //  cout<<"Value of small & big"<<small[i]<<big[j]<<endl;

                if(small[i]==big[j])
                {
                   // cout<<"Value of smallsize & bigsize"<<i<<j<<endl;
                   // cout<<small[i]<<big[j]<<endl;
                    i++;
                    
                    count++;
                }
                j++;
               // cout<<i<<endl;
            }
           // cout<<j<<endl;
        
        cout<<count<<endl;
        if(count==small.size()) return true;
        else return false;
    }
};

int main() {
    Solution solution;

    string small, big;
     

    if (solution.isSubsequence("abc", "ahbgdc")) {
        cout << "'" << small << "' is a subsequence of '" << big << "'." << endl;
    } else {
        cout << "'" << small << "' is NOT a subsequence of '" << big << "'." << endl;
    }
}
