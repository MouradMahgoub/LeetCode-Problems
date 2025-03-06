class Solution {
public:
    int n, m;
    string s1, s2, s3;
    vector<vector<int>> memo;
    bool foo(int i, int j, int k){
        if(k == s3.size()) return memo[i][j] = true;
        if(memo[i][j] != -1) return memo[i][j];
        bool ans = false;
        if(i < n && s3[k] == s1[i])
           ans = ans || foo(i+1, j, k+1);
        if(j < m && s3[k] == s2[j])
            ans = ans || foo(i, j+1, k+1);
        return memo[i][j] = ans;
    }
    bool isInterleave(string ss1, string ss2, string ss3) {
        n = ss1.size(); m = ss2.size();
        memo.resize(n+1, vector<int>(m+1, -1));
        if(n + m != ss3.size()) return false;
        s1 = ss1; s2 = ss2; s3 = ss3;
        return foo(0, 0, 0);
    }
};