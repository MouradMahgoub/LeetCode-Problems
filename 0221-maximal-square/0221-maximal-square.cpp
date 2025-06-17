class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // dp -> save max side
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                dp[i+1][j+1] = matrix[i][j] - '0';
        int maxSide = 0;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(dp[i][j] == 0) continue;
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                maxSide = max(maxSide, dp[i][j]);
            }
        }
        return maxSide*maxSide;
    }
};





        // int ans=0;
        // vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        // for(int i=0; i<matrix.size(); i++)
        //     for(int j=0; j<matrix[0].size(); j++)
        //         dp[i][j] = matrix[i][j] - '0';
        // for(int i=dp.size()-2; i>=0; i--){
        //     for(int j=dp[0].size()-2; j>=0; j--){
        //         if(dp[i][j] == 0) continue;
        //         dp[i][j] += min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
        //         ans = max(ans, dp[i][j]);
        //     }
        // }
        // return ans*ans;