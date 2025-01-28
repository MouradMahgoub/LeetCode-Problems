class Solution {
public:
    bool valid (int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int dfs (int i, int j, vector<vector<int>>& grid) {
        if(!valid(i, j, grid.size(), grid[0].size()) || grid[i][j] == 0) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        return val 
            + dfs(i+1, j, grid)
            + dfs(i, j+1, grid)
            + dfs(i-1, j, grid)
            + dfs(i, j-1, grid);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++)   
            for(int j=0; j<grid[0].size(); j++)
                if(grid[i][j] > 0)
                    ans = max(ans, dfs(i, j, grid));
        return ans;   
    }
};