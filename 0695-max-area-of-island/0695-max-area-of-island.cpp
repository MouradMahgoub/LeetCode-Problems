class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int dfs (int i, int j, vector<vector<int>>& grid) {
        if(!valid(i, j) || visited[i][j] || grid[i][j] == 0) return 0;
        visited[i][j] = true;
        return 1 + dfs(i+1, j, grid)
                 + dfs(i, j+1, grid)
                 + dfs(i-1, j, grid)
                 + dfs(i, j-1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;        
        n = grid.size(); m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!visited[i][j] && grid[i][j] == 1)
                    ans = max(ans, dfs(i, j, grid));
        return ans;
    }
};