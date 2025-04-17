#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        int n = 100000000;
        while (n >= 0) {
            if (head->next == nullptr) {
                return false;
            }
            head = head->next;
            n--;
        }
        return true;
    }
};

int main() {
    // Create list: 3 -> 2 -> 0 -> -4
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create cycle: tail connects to node2
    node4->next = node2;

    Solution sol;
    bool result = sol.hasCycle(node1);

    if (result) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // Note: In real code, you should free memory. Avoiding it here due to the cycle.

    return 0;
}
