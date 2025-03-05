class Solution {
public:
    int dp[38] = {0};
    
    Solution() {
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<38; i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
    }
    
    int tribonacci(int n) {
        return dp[n];
    }
};