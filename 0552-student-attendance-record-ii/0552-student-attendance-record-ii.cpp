class Solution {
public:
    vector<vector<vector<long>>> memo;
    const int MOD = 1000000007;
    long foo (int n, int i, int cntA, int cntL) {
        if(cntA >= 2 || cntL >= 3) return 0;
        if(i == n) return 1;
        if(memo[i][cntA][cntL] != -1) 
            return memo[i][cntA][cntL];
        memo[i][cntA][cntL] =  (
                                foo(n, i+1, cntA+1, 0)%MOD + 
                                foo(n, i+1, cntA, cntL+1)%MOD + 
                                foo(n, i+1, cntA, 0)%MOD
                                )%MOD;
        return memo[i][cntA][cntL]; 
    }
    int checkRecord(int n) {
        memo = vector<vector<vector<long>>>(n, vector<vector<long>>(2, vector<long>(3, -1)));
        return foo(n, 0, 0, 0);
    }
};