class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    void dfs (int node) {
        visited[node] = true;
        for(int nei : adj[node])
            if(!visited[nei]) dfs(nei);

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        adj.resize(n);
        visited.resize(n, false);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(isConnected[i][j])
                    adj[i].push_back(j);
        int numOfCities = 0;
        for(int i=0; i<n; i++)
            if(!visited[i]){
                dfs(i);
                numOfCities++;
            }
        return numOfCities;
    }
};