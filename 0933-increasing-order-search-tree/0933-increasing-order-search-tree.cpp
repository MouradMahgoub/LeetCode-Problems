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
    vector<TreeNode*> v;
    void foo(TreeNode* root){
        if(!root) return;
        foo(root->left);
        v.push_back(root);
        foo(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        foo(root);
        for(int i=0; i<v.size()-1; i++){
            v[i]->left = NULL;
            v[i]->right = v[i+1];
        }
        v[v.size()-1]->left = NULL;
        v[v.size()-1]->right = NULL;
        return v[0];
    }
};