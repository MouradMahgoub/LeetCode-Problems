class Solution {
public:
    int n, m;
    string s1, s2, s3;
    vector<vector<int>> memo;
    bool foo(int i, int j){
        if(memo[i][j] != -1) return memo[i][j];
        if(i + j == s3.size()) return memo[i][j] = true;
        if(i == n) {
            if(s3[i+j] == s2[j] && foo(i, j+1)) return memo[i][j] = true; 
            return false;
        }
        if(j == m){
            if(s3[i+j] == s1[i] && foo(i+1, j)) return memo[i][j] = true;
            return false;
        }

        if(s3[i+j] == s1[i] && foo(i+1, j)) return memo[i][j] = true; 
        if(s3[i+j] == s2[j] && foo(i, j+1)) return memo[i][j] = true; 
        return memo[i][j] = false;
    }
    bool isInterleave(string ss1, string ss2, string ss3) {
        n = ss1.size(); m = ss2.size();
        memo.resize(n+1, vector<int>(m+1, -1));
        if(n + m != ss3.size()) return false;
        s1 = ss1; s2 = ss2; s3 = ss3;
        return foo(0, 0);
    }
};