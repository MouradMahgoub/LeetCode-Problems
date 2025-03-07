class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<n+1; i++) dp[i][0] = i;
        for(int j=1; j<m+1; j++) dp[0][j] = j;
        for(int i=1; i<n+1; i++)
            for(int j=1; j<m+1; j++)
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
        return dp[n][m];
    }

    // vector<vector<int>> memo;
    // int foo (int i, int j, string& s1, string& s2) {
    //     if(memo[i][j] != -1) return memo[i][j];
    //     if(i == s1.size()) return memo[i][j] = s2.size() - j;
    //     if(j == s2.size()) return memo[i][j] = s1.size() - i;
    //     if(s1[i] == s2[j]) 
    //         return memo[i][j] = foo(i+1, j+1, s1, s2);
    //     return memo[i][j] = 1 + min({foo(i+1, j+1, s1, s2), foo(i+1, j, s1, s2), foo(i, j+1, s1, s2)});

    // }
    //     memo.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
    //     return foo(0, 0, s1, s2);

        // int n=s1.size(), m=s2.size();
        // vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // for(int i=0; i<=n; i++)
        //     dp[i][0] += i;
        // for(int j=0; j<=m; j++)
        //     dp[0][j] += j;
        // for(int i=1; i<=n; i++)
        //     for(int j=1; j<=m; j++){
        //         dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        //         if(s1[i-1] == s2[j-1])
        //             dp[i][j] = dp[i-1][j-1];
        //     }
        // return dp[n][m];

    // vector<vector<int>> memo;
    // int minDistance(string s1, string s2) {
    //     memo = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
    //     return foo(0, 0, s1, s2);
    // }

    // int foo (int i, int j, string s1, string s2) {
    //     if(j == s2.size()) return s1.size() - i;
    //     if(i == s1.size()) return s2.size() - j;

    //     if(memo[i][j] != -1) return memo[i][j];

    //     if(s1[i] == s2[j])
    //         return memo[i][j] = foo(i+1, j+1, s1, s2);
        
    //     return memo[i][j] = 1 + min(
    //                 foo(i, j+1, s1, s2),
    //             min(foo(i+1, j, s1, s2), 
    //                 foo(i+1, j+1, s1, s2))
    //             );
    // }
};