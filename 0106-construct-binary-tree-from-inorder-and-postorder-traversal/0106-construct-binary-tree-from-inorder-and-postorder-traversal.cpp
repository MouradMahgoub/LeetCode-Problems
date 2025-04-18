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
    unordered_map<int, int> mp;
    TreeNode* foo(int si, int ei, int sp, int ep, vector<int>& inorder, vector<int>& postorder){
        if(si > ei) return NULL;
        TreeNode* root = new TreeNode(postorder[ep]);
        int leftSize = mp[root->val] - si;
        root->left = foo(si, si+leftSize-1, sp, sp+leftSize-1, inorder, postorder);
        root->right = foo(si+leftSize-1+2, ei, sp+leftSize-1+1, ep-1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) mp[inorder[i]] = i;
        return foo(0, n-1, 0, n-1, inorder, postorder);
    }
};