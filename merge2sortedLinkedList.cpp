#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *prev = nullptr;
        ListNode *next;
        ListNode *head = nullptr;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                if (prev == nullptr) head = list1;
                else prev->next = list1;
                prev = list1;
                list1 = list1->next;
            } else {
                if (prev == nullptr) {
                    head = list2;
                    prev = list2;
                    next = list2->next;
                    list2->next = list1;
                    list2 = next;
                } else {
                    prev->next = list2;
                    next = list2->next;
                    list2->next = list1;
                    prev = list2;
                    list2 = next;
                }
            }
        }

        if (prev != nullptr) {
            prev->next = (list1 != nullptr) ? list1 : list2;
        }

        if (head == nullptr) {
            head = (list1 != nullptr) ? list1 : list2;
        }

        return head;
    }
};

// Utility to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

// Utility to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6};

    ListNode* list1 = createList(v1);
    ListNode* list2 = createList(v2);

    Solution solution;
    ListNode* merged = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
