class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        queue<pair<int, int>> q1, q2;
        vector<vector<bool>> visited1(n, vector<bool>(m, false)), visited2(n, vector<bool>(m, false));
        for(int j=0; j<m; j++){
            q1.push({0, j});    
            q2.push({n-1, j});
        }
        for(int i=1; i<n; i++){
            q1.push({i, 0});
            q2.push({i-1, m-1});
        }
        // while(!q1.empty()){
        //     auto [r, c] = q1.front(); q1.pop();
        //     cout << r << " " << c << ",";
        // }
        // cout << "\n";
        // while(!q2.empty()){
        //     auto [r, c] = q2.front(); q2.pop();
        //     cout << r << " " << c << ",";
        // }
        bfs(heights, q1, visited1);
        bfs(heights, q2, visited2);
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(visited1[i][j] && visited2[i][j]) ans.push_back({i, j});
        return ans;
    }
    void bfs (vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        int x[] = {0, 1, 0, -1};
        int y[] = {1, 0, -1, 0};
        int n = visited.size(), m = visited[0].size();
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [r, c] = q.front(); q.pop();
                // if(r < 0 || r > n-1 || c < 0 || c > m-1 || visited[r][c]) continue;
                // if(visited[r][c]) 
                visited[r][c] = true;
                for(int i=0; i<4; i++){
                    int newR = r + x[i], newC = c + y[i];
                    if(newR < 0 || newR > n-1 || newC < 0 || newC > m-1 || visited[newR][newC]
                    || heights[r][c] > heights[newR][newC]) continue;
                    q.push({newR, newC});
                    visited[newR][newC] = true;
                }
            }
        }
    }
};