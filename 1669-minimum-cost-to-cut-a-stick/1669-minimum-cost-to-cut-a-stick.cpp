class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(100+5, vector<int>(100+5, 0));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        for(int len=2; len<cuts.size(); len++){
            for(int i=0; i<cuts.size() - len; i++){
                int j = i + len;
                dp[i][j] = 1e9;
                for(int k=i+1; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }
        return dp[0][cuts.size()-1];
    }
};


    // vector<vector<int>> memo;
        // return foo(0, cuts.size()-1, cuts);
    // int foo(int start, int end, vector<int>& cuts) {
    //     if(start - end == 1) return 0;
    //     if(memo[start][end] != -1) return memo[start][end];
    //     int ans = 1e9;
    //     for(int i=start+1; i<end; i++){
    //         ans = min(ans,
    //             cuts[end]-cuts[start] + foo(start, i, cuts) + foo(i, end, cuts));
    //     }
    //     return memo[start][end] = (ans == 1e9 ? 0 : ans);
    // }