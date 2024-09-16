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
    int dfs (TreeNode* root, int maxVal) {
        if(!root) return 0;
        int good = 0;
        if(root->val >= maxVal) good++;
        maxVal = max(maxVal, root->val);
        return good + dfs(root->left, maxVal) 
                    + dfs(root->right, maxVal);
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root, -1e9);
    }
};
    // int dfs (TreeNode* root, int maxValue) {
    //     if(!root) return 0;
    //     maxValue = max(maxValue, root->val);
    //     int good = 0;
    //     if(root->val >= maxValue) good++;
    //     return good + dfs(root->left, maxValue) 
    //                 + dfs(root->right, maxValue);
    // }