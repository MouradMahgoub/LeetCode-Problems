class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, pair<int, int>>> pq;
        unordered_set<int> visited;
        int ans=0;
        pq.push({0, {0, 0}});
        while(visited.size() < points.size()){
            auto [cost, edge] = pq.top(); pq.pop();
            auto [prev, curr] = edge;
            if(visited.count(curr)) continue;
            visited.insert(curr);
            int x = points[curr][0], y = points[curr][1]; 
            ans -= cost;
            for(int i=0; i<points.size(); i++){
                if(visited.count(i)) continue;
                int xi = points[i][0], yi = points[i][1];
                int costi = abs(x - xi) + abs(yi - y);
                pq.push({-costi, {curr, i}});
            }
        }
        return ans;
    }
};