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
    vector<int> getInfo (int index, string s) {
        int depth = 0, i = 0, num = 0;
        for(i=index; i<s.size(); i++){
            if(s[i] == '-') depth++;
            else {
                num = 0;
                while(i < s.size() && s[i] != '-')
                    num = num*10 + (s[i++] - '0');
                break;
            }
        }
        return {num, depth, i};
    }

    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*> st;
        int j = 0, num = 0, depth = 0;
        while(j < s.size() && s[j] != '-')
            num = num*10 + (s[j++] - '0');
        TreeNode* root = new TreeNode (num);
        st.push(root);
        for(int i=j; i<s.size(); i++){
            vector<int> v = getInfo(i, s);
            num = v[0]; depth = v[1];
            i = v[2] - 1;
            TreeNode* child = new TreeNode(num);
            while(st.size() > depth) st.pop();
            TreeNode* parent = st.top();
            if(!parent->left) parent->left = child;
            else parent->right = child;
            st.push(child);
        }
        return root;
    }
};