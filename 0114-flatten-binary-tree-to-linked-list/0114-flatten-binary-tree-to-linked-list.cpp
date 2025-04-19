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
    TreeNode* foo (TreeNode* root) {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode* leftEnd = foo(root->left);
        TreeNode* rightEnd = foo(root->right);
        if(leftEnd) {
            leftEnd->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return rightEnd ? rightEnd : leftEnd;
    }

    void flatten(TreeNode* root) {
        foo(root);
    }
};