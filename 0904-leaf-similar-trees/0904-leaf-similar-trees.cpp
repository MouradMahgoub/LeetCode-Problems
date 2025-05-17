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
    vector<int> v1, v2;
    void dfs (TreeNode* root, int tree){
        if(!root) return;
        if(!root->left && !root->right){
            if(tree == 1) v1.push_back(root->val);
            else v2.push_back(root->val);
            return;
        }
        dfs(root->left, tree);   
        dfs(root->right, tree);   
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, 1);
        dfs(root2, 2);
        return v1 == v2;
    }
};