#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n != m) return false;

        unordered_map<char, int> hashMap1;
        unordered_map<char, int> hashMap2;

        for (int i = 0; i < n; i++) {
            hashMap1[s[i]]++;
            hashMap2[t[i]]++;
        }

        return hashMap1 == hashMap2;
    }
};

int main() {
    Solution sol;
    
    string s = "listen";
    string t = "silent";

    if (sol.isAnagram(s, t)) {
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    } else {
        cout << "\"" << s << "\" and \"" << t << "\" are not anagrams." << endl;
    }

    return 0;
}
