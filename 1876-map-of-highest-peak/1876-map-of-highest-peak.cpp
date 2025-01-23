class Solution {
public:
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(isWater[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }

        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [i, j] = q.front();
                q.pop();
                isWater[i][j] = cnt;
                for(int k=0; k<4; k++){
                    int ii = i+x[k], jj = j+y[k];
                    if(isValid(ii, jj, n, m) && !visited[ii][jj]) {
                        q.push({ii, jj});
                        visited[ii][jj] = true;
                    }
                }
            }
            cnt++;
        }
        return isWater;
    }

    bool isValid (int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};