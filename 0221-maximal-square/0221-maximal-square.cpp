class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++)
                dp[i][j] = matrix[i][j] - '0';
        for(int i=dp.size()-2; i>=0; i--){
            for(int j=dp[0].size()-2; j>=0; j--){
                if(dp[i][j] == 0) continue;
                dp[i][j] += min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};