class Solution {
public:
    vector<vector<int>> memo;
    int dfs (int i, int j, vector<vector<int>>& v) {
        if(memo[i][j] != 1e9) return memo[i][j];
        if(i == v.size()-1){
            return memo[i][j] = v[i][j];
        }
        return memo[i][j] = v[i][j] + min(dfs(i+1, j, v), dfs(i+1, j+1, v));
    }

    int minimumTotal(vector<vector<int>>& v) {
        memo.resize(v.size()+1, vector<int>(v[v.size()-1].size()+1, 1e9));
        return dfs(0, 0, v);
    }
};



        // vector<vector<int>> dp(triangle);
        // for(int i=triangle.size()-2; i>=0; i--)
        //     for(int j=0; j<triangle[i].size(); j++)
        //         dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
        // return dp[0][0];