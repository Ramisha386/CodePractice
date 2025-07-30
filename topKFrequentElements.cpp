#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;  // count frequencies
        }

        vector<pair<int, int>> arr;
        for (auto& p : count) {
            arr.push_back({p.second, p.first}); // store as {frequency, number}
        }

        sort(arr.rbegin(), arr.rend()); // sort descending by frequency

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1,1,1,2,2,3,3,3,3,4};
    int k = 2;

    vector<int> ans = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
