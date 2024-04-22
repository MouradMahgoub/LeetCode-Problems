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
    vector<vector<int>> levelOrder(TreeNode* root) {
                vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s);
            for(int i=0; i<s; i++){
                TreeNode* currNode = q.front();
                temp[i] = currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};