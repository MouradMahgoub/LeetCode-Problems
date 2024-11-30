class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        for(int i=1; i<str1.size()+1; i++)
            for(int j=1; j<str2.size()+1; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
            }

        string ans = "";
        int i=str1.size(), j=str2.size();
        while(i > 0 ||  j > 0){
            if(i > 0 && j > 0 && str1[i-1] == str2[j-1])
                ans += str1[i-1],  i--, j--;
            else if(i > 0 && dp[i][j] == dp[i-1][j])
                ans += str1[i-1], i--;
            else //(j > 0 && dp[i][j] == dp[i][j-1])
                ans += str2[j-1], j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};