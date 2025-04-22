#include <iostream>
#include <string>

using namespace std;
class Solution {
    public:
    string reverseVowels(string s) {
            int first=0;
            int last=s.size()-1;
            while(first<last)
            {
                //cout<<"Beginning of the loop s[first] "<<s[first]<< "  s[last] "<<s[last]<<endl;
                while(first<last && (s[first]!='a' && s[first]!='e' && s[first]!='i' && s[first]!='o' && s[first]!='u' && s[first]!='A' && s[first]!='E' && s[first]!='I' && s[first]!='O' &&s[first]!='U' ))
                {
                    first++;    
                }
                while(first<last && (s[last]!='a' && s[last]!='e' && s[last]!='i' && s[last]!='o' && s[last]!='u' && s[last]!='A' && s[last]!='E' && s[last]!='I' && s[last]!='O' && s[last]!='U' ))
                {
                    last--;   
                }
                //cout<<"s[first] "<<s[first]<< "  s[last] "<<s[last]<<endl;
                
                if(first<last)
                {
                    char temp = s[last];
                    s[last] = s[first];
                    s[first] = temp;
                    first++;
                    last--;
                }
    
            }
            return s;
            
        }
    };
int main() {
    
    

    Solution sol;
    string result = sol.reverseVowels("IceCreAm");

    
    cout << "The string is " <<result<< endl;
    

    return 0;
}