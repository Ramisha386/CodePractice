#include <iostream>
#include <string>

using namespace std;
class Solution {
    public:
        bool isPalindrome(string s) {
            int n=s.size()-1;
            int first=0;
            int last=s.size()-1;
            int flag=0;
            while(first<last)
            {
                while(first<last && !isalnum(s[first]))
                {
                    first++;    
                }
                while(first<last && !isalnum(s[last]))
                {
                    last--;   
                }
              //  cout<<"s[first] "<<s[first]<< "  s[last] "<<s[last]<<endl;
                if(tolower(s[first])!=tolower(s[last]))
                {
                    flag=1;
                    break;
                }
                first++;
                last--;
    
            }
            if(flag==1) return false;
            else return true;
            
        }
    };
int main() {
    
    

    Solution sol;
    bool result = sol.isPalindrome("A man, a plan, a canal: Panama");

    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}