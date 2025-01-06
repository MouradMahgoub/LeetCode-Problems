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
    vector<string> ans;

    void foo (TreeNode* root, string temp) {
        temp += to_string(root->val);
        if(!root->left && !root->right) ans.push_back(temp);

        temp += "->";
        if(root->left) foo(root->left, temp);
        if(root->right) foo(root->right, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ans;
        foo(root, "");
        return ans;    
    }
};



