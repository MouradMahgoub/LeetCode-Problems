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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            long double ave = 0;
            for(int i=0; i<s; i++){
                TreeNode* curr = q.front();
                ave += (curr->val * 1.0)/s;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            ans.push_back(ave);
        }
        return ans;
    }
};