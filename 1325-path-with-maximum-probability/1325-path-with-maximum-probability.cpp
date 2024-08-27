class Solution {
public:
    vector<vector<pair<int, double>>> adj;
    void form_graph (int n, vector<vector<int>>& edges, vector<double>& succProb) {
        adj.resize(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        form_graph(n, edges, succProb);
        vector<int> visited(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while(!pq.empty()){
            auto [curr_prob, curr] = pq.top(); pq.pop();
            visited[curr]++;
            if(curr == end) return curr_prob;
            for(auto [nei, edge_prob] : adj[curr]){
                if(visited[nei]) continue;
                pq.push({curr_prob*edge_prob, nei});
            }
        }
        return 0;
    }
};