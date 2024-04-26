class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.begin(), grid.end());
        int n = grid.size(), ans = INT_MAX;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int mn = INT_MAX;
                for(int k=0; k<n; k++){
                    if(k != j) mn = min(mn, dp[i+1][k]);
                }
                dp[i][j] += mn;
            }
        }
        for(int i=0; i<n; i++)
            ans = min(ans, dp[0][i]);
        return ans; 
    }
};