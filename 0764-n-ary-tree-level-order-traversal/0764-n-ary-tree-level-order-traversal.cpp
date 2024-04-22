/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp(s);
            for(int i=0; i<s; i++){
                Node* currNode = q.front();
                temp[i] = currNode->val;
                for(auto node : currNode->children){
                    q.push(node);
                }
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};