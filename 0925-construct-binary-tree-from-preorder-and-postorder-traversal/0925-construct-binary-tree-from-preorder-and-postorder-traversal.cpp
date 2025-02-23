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
    TreeNode* foo(vector<int>& preV, vector<int>& postV, int s1, int e1, int s2, int e2){
        if(s1 == e1) return new TreeNode (preV[s1]);
        if(s1 > e1) return NULL;
        TreeNode* root = new TreeNode (preV[s1]);
        int lenLeft = mp[preV[s1+1]]+1 - s2;
        // for(int i=s2; i<=e2; i++){
        //     lenLeft++;
        //     if(postV[i] == preV[s1+1]) break;
        // }
        root->left = foo(preV, postV, s1+1, s1+lenLeft, s2, s2+lenLeft-1);
        root->right = foo(preV, postV, s1+lenLeft+1, e1, s2+lenLeft, e2-1);
        return root;
    }

    unordered_map<int, int> mp;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0; i<postorder.size(); i++) mp[postorder[i]] = i;
        return foo(preorder, postorder, 0, preorder.size()-1, 0, preorder.size()-1);
    }
};