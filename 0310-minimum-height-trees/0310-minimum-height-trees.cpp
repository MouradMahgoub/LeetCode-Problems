class Solution {
public:
    vector<vector<int>> formGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = formGraph(n, edges);
        vector<int> nodesDegree(n, 0);
        unordered_set<int> nodes;
        queue<int> leaves;
        for(int i=0; i<n; i++){
            nodes.insert(i);
            nodesDegree[i] = adj[i].size();
            if(nodesDegree[i] == 1) leaves.push(i);
        }
        while(nodes.size() > 2){
            int s = leaves.size();
            for(int i=0; i<s; i++){
                int currLeave = leaves.front();
                nodes.erase(currLeave);
                leaves.pop();
                for(auto neighbour : adj[currLeave]){
                    if(--nodesDegree[neighbour] == 1) leaves.push(neighbour);
                }
            }
        }
        vector<int> ans(nodes.begin(), nodes.end());
        return ans;
    }
};



        // vector<pair<int, int>> heights;
        // vector<vector<int>> tree = formGraph(n, edges);
        // int minHieght = INT_MAX;
        // for(int i=0; i<n; i++){
        //     vector<bool> visited(n, false);
        //     queue<int> q;
        //     q.push(i);
        //     visited[i] = true;
        //     int tempHieght = -1;
        //     while(!q.empty()){
        //         int s = q.size();
        //         for(int j=0; j<s; j++){
        //             int curr = q.front();
        //             for(auto adj : tree[curr]){
        //                 if(!visited[adj]){
        //                     q.push(adj);
        //                     visited[adj] = true;
        //                 }
        //             }
        //             q.pop();
        //         }
        //         tempHieght++; 
        //     }
        //     minHieght = min(minHieght, tempHieght);
        //     heights.push_back(make_pair(i, tempHieght));
        // }
        // vector<int> ans;
        // for(auto p : heights)
        //     if(p.second == minHieght)
        //         ans.push_back(p.first);
        // return ans;