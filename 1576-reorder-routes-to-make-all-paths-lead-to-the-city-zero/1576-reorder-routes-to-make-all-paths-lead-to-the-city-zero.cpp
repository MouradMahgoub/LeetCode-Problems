class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    int cnt = 0;
    void dfs (int node) {
        visited[node] = true;
        for(int nei : adj[node]){
            if(!visited[abs(nei)]){
                cnt += (nei > 0);
                dfs(abs(nei));
            } 
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n, false);
        for(auto conn : connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(-u);
        }
        dfs(0);
        return cnt;
    }
};