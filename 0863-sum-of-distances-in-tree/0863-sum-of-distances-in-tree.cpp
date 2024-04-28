class Solution {
public:
    vector<vector<int>> graph;
    vector<int> countNodes, res; 
    void dfs1(int node, int parent){
        for(int child : graph[node]){
            if(child == parent) continue;
            dfs1(child, node);
            countNodes[node] += countNodes[child];
            res[node] += res[child] + countNodes[child];
        }    
        countNodes[node]++;
    }
    void dfs2(int node, int parent){
        for(int child : graph[node]){
            if(child == parent) continue;                   //n
            res[child] = res[node] - countNodes[child] + countNodes[0] - countNodes[child];    
            dfs2(child, node);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        countNodes.resize(n, 0), res.resize(n, 0); 
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};