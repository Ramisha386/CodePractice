#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;
    vector<char> chars = {'h', 'e', 'l', 'l', 'o'};

    cout << "Before: ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    sol.reverseString(chars);

    cout << "After:  ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
