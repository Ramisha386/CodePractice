#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest kthLargest(k, nums);

    cout << "After adding 3: " << kthLargest.add(3) << endl;  // returns 4
    cout << "After adding 5: " << kthLargest.add(5) << endl;  // returns 5
    cout << "After adding 10: " << kthLargest.add(10) << endl; // returns 5
    cout << "After adding 9: " << kthLargest.add(9) << endl;  // returns 8
    cout << "After adding 4: " << kthLargest.add(4) << endl;  // returns 8

    return 0;
}
