class Solution {
public:
    bool valid (int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m; 
    }

    void dfs (int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if(!valid(i, j, grid.size(), grid[0].size()) || visited[i][j] || grid[i][j] == 0) return;
        visited[i][j] = 1;
        dfs(i+1, j, grid, visited);
        dfs(i-1, j, grid, visited);
        dfs(i, j+1, grid, visited);
        dfs(i, j-1, grid, visited);
    }

    int getNumberOfIslands (vector<vector<int>>& grid) {
        int numberOfIslands = 0;
        vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(i, j, grid, visited);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }

    int minDays(vector<vector<int>>& grid) {
        int numberOfIslands = getNumberOfIslands(grid);
        if(numberOfIslands != 1) return 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int temp = getNumberOfIslands(grid);
                    if(temp != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};