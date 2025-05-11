#include <iostream>
#include <vector>

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            preorder(root, result);
            return result;
        }
    
    private:
        void preorder(TreeNode* node, vector<int>& result) {
            if (node != nullptr) {
                result.push_back(node->val);
                preorder(node->left, result);
                preorder(node->right, result);
            }
        }
    };
    

int main() {
    // Construct the binary tree:
    //      1
    //       \
    //        2
    //       /
    //      3

    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node3, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, node2);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Inorder traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup allocated memory
    delete node3;
    delete node2;
    delete root;

    return 0;
}
