class Solution {
public:
    // int dfs(vector<vector<int>> &dp, int i, int j, string s1, string s2) {
    //     if(i > dp.size()-1 || j > dp[0].size()-1) return 0;
    //     if(s1[i] == s2[j]) return 1 + dfs(dp, i+1, j+1, s1, s2);
    //     return max(dfs(dp, i+1, j, s1, s2), dfs(dp, i, j+1, s1, s2));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        // return dfs(dp, 0, 0, text1, text2);
        for(int i=text1.size()-1; i>=0; i--){
            for(int j=text2.size()-1; j>=0; j--){
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};