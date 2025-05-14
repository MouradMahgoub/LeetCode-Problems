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
    void foo(TreeNode* root, string curr){
        curr += to_string(root->val);
        if(!root->left && !root->right){
            ans += stoi(curr);
            return;
        }
        if(root->left) foo(root->left, curr);
        if(root->right) foo(root->right, curr);
    }
    int sumNumbers(TreeNode* root) {
        foo(root, "");
        return ans;
    }
};