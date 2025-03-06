class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        int x = 0, y = 0;
        for(int i=0; i<n; i++) dp[i][i] = true;
        for(int i=0; i<n-1; i++) 
            if((s[i] == s[i+1])){
                dp[i][i+1] = true;
                x = i; y = i+1;
            }
        for(int i=2; i<n; i++)
            for(int j=0; j<n-i; j++)
                if(s[j] == s[j+i] && dp[j+1][j+i-1]){
                    dp[j][j+i] = true;
                    x = j; y = j+i;
                }
        return s.substr(x, y-x+1);
    }
};


        // int n = s.size();
        // vector<vector<bool>> dp(n+5, vector<bool>(n+5));
        // pair<int, int> ans = {0, 0};
        // for(int i=0; i<n; i++) dp[i][i] = true;
        // for(int i=0; i<n-1; i++) 
        //     if(s[i] == s[i+1]){
        //         dp[i][i+1] = true;
        //         ans = {i, i+1};
        //     }
        // for(int i=2; i<n; i++)
        //     for(int j=0; j+i<n; j++)
        //         if(s[j] == s[j+i] && dp[j+1][j+i-1]){
        //             dp[j][j+i] = true;
        //             ans = {j, j+i};
        //         }
        // return s.substr(ans.first, (ans.second-ans.first+1));