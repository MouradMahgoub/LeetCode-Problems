class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) return cost[0];
        vector<int> dp(cost.size()+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size(); i++)
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};
    // vector<int> memo;
    // int minCostClimbingStairs(vector<int>& cost) {
    //     memo = vector<int>(cost.size()+1, -1);
    //     return min(foo(0, cost), foo(1, cost));
    // }
    // int foo (int i, vector<int>& cost) {
    //     if(i > cost.size()-1) return 0;
    //     if(memo[i] != -1) return memo[i];
    //     memo[i] = cost[i] + min(foo(i+1, cost), foo(i+2, cost));
    //     return memo[i];
    // }