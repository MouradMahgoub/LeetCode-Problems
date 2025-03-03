class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<pair<int, int>> q;
        bool flag = true;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(g[i][j] == 1) flag = false; 
                if(g[i][j] == 2) q.push({i, j});
            }
        
        if(flag) return 0;

        int dirX[] = {0, 1, 0, -1};
        int dirY[] = {1, 0, -1, 0};
        int steps = -1;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [i, j] = q.front(); q.pop();
                for(int k=0; k<4; k++){
                    int x = i+dirX[k];
                    int y = j+dirY[k];
                    if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 1){
                        q.push({x, y});
                        g[x][y] = 2;
                    }
                }
            }
            steps++;
        }

         for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(g[i][j] == 1) return -1;

        return steps;
    }
};