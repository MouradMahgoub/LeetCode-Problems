class Solution {
public:
    int dp[100] = {0};
    
    Solution() {
        dp[1] = 1;
        dp[2] = 1;
    }
    
    int tribonacci(int n) {
        if(!n) return 0;
        if(dp[n]) return dp[n];
        dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return dp[n];
    }
};