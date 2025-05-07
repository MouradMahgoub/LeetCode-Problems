class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        priority_queue<vector<int>> pq;
        pq.push({-0, 0, 0});
        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!pq.empty()){
            auto v = pq.top(); pq.pop();
            int currTime = -v[0], i = v[1], j = v[2];
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(i == n-1 && j == m-1) return currTime;
            for(int idx=0; idx<4; idx++){
                int ii = i + dirs[idx][0], jj = j + dirs[idx][1];
                if(ii < 0 || ii > n-1 || jj < 0 || jj > m-1) continue;
                int newTime = max(currTime, moveTime[ii][jj]) + 1;
                if(newTime < minTime[ii][jj]){
                    minTime[ii][jj] = newTime;
                    pq.push({-newTime, ii, jj});
                }
            }
        }
        return -1;
    }
};