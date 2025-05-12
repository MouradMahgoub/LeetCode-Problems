/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> orig;
    unordered_map<int, Node*> copy;

    void dfs (Node* node, unordered_map<int, Node*>& mp) {
        if(mp.find(node->val) != mp.end()) return;
        mp[node->val] = node;
        for(auto nei : node->neighbors)
            dfs(nei, mp);
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        dfs(node, orig);
        int n = orig.size();
        for(int i=1; i<=n; i++) copy[i] = new Node(i);
        for(auto [val, node] : orig)
            for(auto nei : node->neighbors)
                copy[val]->neighbors.push_back(copy[nei->val]); 
        return copy[1];
    }
};