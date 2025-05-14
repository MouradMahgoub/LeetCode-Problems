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
    int ans = 0;
    int foo(TreeNode* root, string curr){
        if(!root) return 0;
        curr += to_string(root->val);
        if(!root->left && !root->right) return stoi(curr);
        return foo(root->left, curr) + foo(root->right, curr);
    }
    int sumNumbers(TreeNode* root) {
        return foo(root, "");
    }
};