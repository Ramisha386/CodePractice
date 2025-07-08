#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> h;
        int max_freq = 0;
        int i = 0;
        int j = 0;
        int max_count = 0;

        while (j < n) {
            h[s[j]]++;
            max_freq = max(max_freq, h[s[j]]);
            if ((1 + j - i) - max_freq > k) {
                h[s[i]]--;
                i++;
            }
            max_count = max(max_count, (j - i) + 1);
            j++;
        }
        return max_count;
    }
};

int main() {
    Solution sol;
    string s = "KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF";
    int k = 4;
    int result = sol.characterReplacement(s, k);
    cout << "The length of the longest substring after at most " << k << " replacements is: " << result << endl;
    return 0;
}
