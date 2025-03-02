class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    void dfs(int node){
        visited[node] = true;
        for(int nei : adj[node])
            if(!visited[nei])
                dfs(nei);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        adj.resize(rooms.size());
        visited.resize(rooms.size(), false);
        for(int i=0; i<rooms.size(); i++)
            for(int j=0; j<rooms[i].size(); j++)
                adj[i].push_back(rooms[i][j]);
        dfs(0);
        for(bool b : visited) if(!b) return false;
        return true;
    }
};