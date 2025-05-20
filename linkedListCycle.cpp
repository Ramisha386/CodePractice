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
        if (head == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle (tail connects to node2)

    Solution solution;
    bool result = solution.hasCycle(node1);

    if (result) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // NOTE: In a real-world program, free memory carefully if no cycle exists
    // and handle cycles cautiously to avoid infinite loops during cleanup.

    return 0;
}
