#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// Helper function to print the tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    // Construct the binary tree:
    //       4
    //     /   \
    //    2     7
    //   / \   / \
    //  1   3 6   9

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    cout << "Original tree (level order): ";
    printLevelOrder(root);

    Solution sol;
    TreeNode* invertedRoot = sol.invertTree(root);

    cout << "Inverted tree (level order): ";
    printLevelOrder(invertedRoot);

    return 0;
}
