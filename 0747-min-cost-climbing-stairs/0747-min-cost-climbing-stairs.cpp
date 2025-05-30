class Solution {
public:
    vector<int> memo;
    int foo (vector<int>& cost, int index) {
        if(index > cost.size()-1) return 0;
        if(memo[index] != -1) return memo[index];
        return memo[index] = cost[index] + min(foo(cost, index+1), foo(cost, index+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memo = vector<int> (cost.size()+2, -1);
        return min(foo(cost, 0), foo(cost, 1));
    }
};
        // if(cost.size() == 1) return cost[0];
        // vector<int> dp(cost.size()+1, 0);
        // dp[0] = 0;
        // dp[1] = 0;
        // for(int i=2; i<=cost.size(); i++)
        //     dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        // return dp[cost.size()];

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