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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int currLevel = 1, maxSum = -1e9, smallestLevel = -1;
        while(!q.empty()){
            int sz = q.size();
            int currSum = 0;
            for(int i=0; i<sz; i++){
                TreeNode* currNode = q.front(); q.pop();
                currSum += currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            if(currSum > maxSum) {
                maxSum = currSum;
                smallestLevel = currLevel;
            }
            currLevel++;
        }
        return smallestLevel;
    }
};