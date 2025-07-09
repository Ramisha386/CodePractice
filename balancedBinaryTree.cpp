#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isBalanced(TreeNode* root) {
        int hleft, hright;
        if (root == nullptr) return true;
        hleft = height(root->left);
        hright = height(root->right);
        if (abs(hleft - hright) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};

int main() {
    // Build the tree from input [1,2,3,4,5,6,null,8]
    //
    //          1
    //        /   \
    //       2     3
    //      / \   /
    //     4   5 6
    //    /
    //   8

    TreeNode* node8 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(4, node8, nullptr);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, nullptr);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    bool balanced = sol.isBalanced(root);

    cout << "Is the tree balanced? " << (balanced ? "Yes" : "No") << endl;

    return 0;
}
