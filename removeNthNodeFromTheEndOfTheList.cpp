#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nxt = head;
        ListNode *p = nullptr;
        ListNode *tail = head;
        int i = 0;

        // Move tail pointer n steps ahead
        while (i != n) {
            tail = tail->next;
            i++;
        }

        // Special case: removing the head
        if (tail == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move all pointers until tail reaches the end
        while (tail != nullptr) {
            p = nxt;
            nxt = nxt->next;
            tail = tail->next;
        }

        // Remove the nth node from end
        p->next = nxt->next;
        delete nxt;

        return head;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(values);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
