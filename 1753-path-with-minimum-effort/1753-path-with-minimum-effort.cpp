class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dp(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.second.first == heights.size()-1 && curr.second.second == heights[0].size()-1) return curr.first;
            for(auto dir : dirs){
                int i = curr.second.first + dir[0];
                int j = curr.second.second + dir[1];
                if(i < 0 || j < 0 || i == heights.size() || j == heights[0].size()) continue;
                int newEffort = max(curr.first, abs(heights[i][j] - heights[curr.second.first][curr.second.second]));
                if(newEffort < dp[i][j]){
                    dp[i][j] = newEffort;
                    pq.push({dp[i][j], {i, j}}); 
                }
            }
        }
        return 0;
    }
};