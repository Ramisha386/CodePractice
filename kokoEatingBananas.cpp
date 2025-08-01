#include <iostream>
using namespace std;

class Solution {
public:
    // helper: can Koko finish eating with this speed?
    bool canEat(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed; // ceil(pile/speed)
            if (hours > h) return false; // too slow
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canEat(piles, h, mid)) {
                ans = mid;       // possible answer
                right = mid - 1; // try smaller speed
            } else {
                left = mid + 1;  // need faster speed
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Minimum eating speed (example 1): " 
         << sol.minEatingSpeed(piles1, h1) << endl;

    // Example 2 (your test case)
    vector<int> piles2 = {1, 1, 1, 999999999};
    int h2 = 10;
    cout << "Minimum eating speed (example 2): " 
         << sol.minEatingSpeed(piles2, h2) << endl;

    return 0;
}
