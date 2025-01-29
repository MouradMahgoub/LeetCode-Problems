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

        for(int i=0; i<n; i++)
            if(!visited[i] && dfs(i, parent[i])) break;
        if(cycle_start == -1){
           return {-1, -1};
        }else{
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for(int v = cycle_end; v != cycle_start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(cycle_start);
            set<pair<int, int>> cycle_edges;
            for(int i=0; i<cycle.size()-1; i++)
                cycle_edges.insert({cycle[i]+1, cycle[i+1]+1});
            for(int i=edges.size()-1; i>=0; i--)
                if(cycle_edges.count({edges[i][0], edges[i][1]}) 
                || cycle_edges.count({edges[i][1], edges[i][0]}))
                    return edges[i];
        }
        return {-1, -1};
    }
};