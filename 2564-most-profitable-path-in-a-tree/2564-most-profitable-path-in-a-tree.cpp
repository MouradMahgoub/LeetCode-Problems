class Solution {
public:
    vector<int> bobStep;
    vector<vector<int>> adj;

    int dfsBob (int node, int parent, int level, int bob) {
        if(node == bob) return bobStep[node] = 0;
        for(int nei : adj[node]){
            if(nei == parent) continue;
            bobStep[node] = max(bobStep[node], dfsBob(nei, node, level+1, bob)+1);
        }
        return bobStep[node];
    }

    int dfsAlice (int node, int parent, int level,vector<int>& amount) {
        int currProfit = 0;
        if(bobStep[node] < 0 || bobStep[node] > level) currProfit = amount[node];
        else if(bobStep[node] == level) currProfit = amount[node]/2;
        else if(bobStep[node] < level) currProfit = 0; 

        if(node != 0 && adj[node].size() == 1){
            cout << currProfit << "\n"; 
            return currProfit;
        } 

        int maxChild = -1e9;
        for(int nei : adj[node]) {
            if(nei == parent) continue;
            maxChild = max(maxChild, dfsAlice(nei, node, level+1, amount));
        }
        cout << currProfit + maxChild << "\n"; 
        return currProfit + maxChild;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bobStep = vector<int> (n, -1e9);
        dfsBob(0, -1, 0, bob);
        for(int i=0; i<n; i++) cout << i << " " << bobStep[i] << "\n";
        return dfsAlice(0, -1, 0, amount);
    }
};