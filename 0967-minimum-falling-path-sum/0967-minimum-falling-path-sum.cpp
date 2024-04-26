class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.begin(), matrix.end());
        int n = matrix.size(), ans = INT_MAX;
        for(int i=n-2; i>=0; i--)
            for(int j=0; j<n; j++)
                dp[i][j] += min(dp[i+1][j], min(j-1<0 ? INT_MAX : dp[i+1][j-1], j+1>n-1 ? INT_MAX : dp[i+1][j+1]));
        for(int i=0; i<n; i++)
        ans = min(ans, dp[0][i]);
        return ans; 
    }
};