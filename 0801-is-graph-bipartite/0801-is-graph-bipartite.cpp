class Solution {
public:
    bool bipartite = true;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<bool> color;

    void dfs (int node, bool nodeColor) {
        visited[node] = true;
        color[node] = nodeColor;

        for(int nei : adjList[node])
            if(!visited[nei])
                dfs(nei, !nodeColor);
            else if(color[nei] == nodeColor)
                bipartite = false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        adjList = graph;
        visited.resize(graph.size(), false);
        color.resize(graph.size());

        for(int i=0; i<graph.size(); i++)
            if(!visited[i])
                dfs(i, true);
                
        return bipartite;    
    }
};