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
    vector<int> v;
    void in_order (TreeNode* root) {
        if(root == NULL) return;
        in_order(root->left);
        v.push_back(root->val);
        in_order(root->right);
    }
    TreeNode* foo (int l, int r) {
        if(l > r) return NULL;
        int mid = l + (r-l)/2;
        return new TreeNode(v[mid], foo(l, mid-1), foo(mid+1, r));

    }
    TreeNode* balanceBST(TreeNode* root) {
        in_order(root);
        return foo(0, int(v.size())-1);
    }
};