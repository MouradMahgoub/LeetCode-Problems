class Solution {
public:
    vector<int> parent;
    vector<bool> visited;
    vector<vector<int>> adjList;
    int cycle_start, cycle_end;

    bool dfs (int node, int par) {
        visited[node] = true;
        for(int nei : adjList[node]){
            if(nei == par) continue;
            if(visited[nei]){
                cycle_start = nei;
                cycle_end = node;
                return true; 
            }
            parent[nei] = node;
            if(dfs(nei, node)) return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adjList = vector<vector<int>>(n);
        visited = vector<bool>(n, false);
        parent = vector<int>(n, -1);
        cycle_start = -1;
        for(auto edge : edges){
            adjList[edge[0]-1].push_back(edge[1]-1);    
            adjList[edge[1]-1].push_back(edge[0]-1);    
        }
        dfs(0, -1);
        unordered_map<int, int> mp;
        mp[cycle_start]++;
        for(int u = cycle_end; u != cycle_start; u = parent[u]) mp[u]++;
        for(int i=edges.size()-1; i>=0; i--)
            if(mp[edges[i][0]-1] && mp[edges[i][1]-1]) return edges[i];
        return {-1, -1};        
    }
};