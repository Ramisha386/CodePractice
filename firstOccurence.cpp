#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main() {
    Solution sol;

    string haystack = "hello";
    string needle = "ll";

    int result = sol.strStr(haystack, needle);

    cout << "The position of \"" << needle << "\" in \"" << haystack << "\" is: " << result << endl;

    return 0;
}
