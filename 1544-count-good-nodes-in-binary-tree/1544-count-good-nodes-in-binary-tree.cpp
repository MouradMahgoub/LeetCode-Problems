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
    int numOfGoodNodes (TreeNode* root, int maxValue) {
        if(!root) return 0;
        maxValue = max(maxValue, root->val);
        int good = 0;
        if(root->val >= maxValue) good++;
        return good + numOfGoodNodes(root->left, maxValue) 
                    + numOfGoodNodes(root->right, maxValue);
    }
    int goodNodes(TreeNode* root) {

        return numOfGoodNodes(root, -1e9);
    }
};