class Solution {
public:
    bool valid(int i, int j, int n, int m, vector<vector<char>>& maze){
        return i >= 0 && j >= 0 && i < n && j < m && maze[i][j] != '+';
    }
    bool goal(int i, int j, int n, int m,vector<int>& enter){
        return !(i == enter[0] && j == enter[1]) &&
        (i == 0 || i == n-1 || j == 0 || j == m-1); 
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& enter) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int x[]  = {1, 0, -1, 0};
        int y[]  = {0, -1, 0, 1};

        q.push({enter[0], enter[1]});
        visited[enter[0]][enter[1]] = true;
        int cnt = 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [i, j] = q.front(); q.pop();
                if(goal(i, j, n, m, enter)) return cnt;
                for(int k=0; k<4; k++){
                    int neiX = i+x[k], neiY = j+y[k];
                    if(valid(neiX, neiY, n, m, maze) && !visited[neiX][neiY]){
                        q.push({neiX, neiY});
                        visited[neiX][neiY] = true;
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};