class Solution {
public:
    bool valid (int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    bool dfs (int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(!valid(i, j, grid1.size(), grid2[0].size()) || !grid2[i][j]) return true;
        bool ans = true;
        if(grid2[i][j] && !grid1[i][j]) ans = false;
        grid1[i][j] = 0;
        grid2[i][j] = 0;
        ans = dfs(i + 1, j, grid1, grid2) && ans;
        ans = dfs(i - 1, j, grid1, grid2) && ans;
        ans = dfs(i, j + 1, grid1, grid2) && ans;
        ans = dfs(i, j - 1, grid1, grid2) && ans;
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(), m=grid2[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]){
                    if(dfs(i, j, grid1, grid2)) {
                        ans++;
                    }
                }
            }
        }    
        return ans;
    }
};