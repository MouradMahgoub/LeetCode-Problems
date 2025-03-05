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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front(); q.pop();
                if(i == 0) ans.push_back(curr->val);
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
            }
        }
        return ans;
    }
};
    //DFS sol
    // vector<int> ans;
    // void dfs (int level, TreeNode* root) {
    //     if(!root) return;
    //     if(ans.size() == level) ans.push_back(root->val);
    //     dfs(level+1, root->right);
    //     dfs(level+1, root->left);
    // }
        // dfs(0, root);
        // return ans;
        //BFS sol
        
        // if(!root) return ans;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int s = q.size();
        //     for(int i=0; i<s; i++){
        //         TreeNode* curr = q.front();
        //         if(!i) ans.push_back(curr->val);
        //         q.pop();
        //         if(curr->right) q.push(curr->right);
        //         if(curr->left) q.push(curr->left);
        //     }
        // }