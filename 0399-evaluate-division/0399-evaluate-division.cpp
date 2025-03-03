class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;

    double dfs (string a, string b) {
        visited[a] = true;
        for(auto [nei, val] : adj[a]){
            if(nei == b) return val;
            double res = -1;
            if(!visited[nei]) res = dfs(nei, b);
            if(res != -1) return val * res;
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& qs) {
        for(int i=0; i<eqs.size(); i++){
            string a = eqs[i][0];
            string b = eqs[i][1];
            double val = vals[i];
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0/val});
        }
        vector<double> ans;
        for(auto q : qs){
            visited.clear();
            string a = q[0];
            string b = q[1];
            if(adj.find(a) == adj.end() || adj.find(b) == adj.end()) ans.push_back(-1.0);
            else if(a == b) ans.push_back(1.0);
            else ans.push_back(dfs(a, b));
        }
        return ans;
    }
};