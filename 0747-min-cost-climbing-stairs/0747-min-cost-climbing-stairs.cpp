class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        memo = vector<int>(cost.size()+1, -1);
        return min(foo(0, cost), foo(1, cost));
    }
    int foo (int i, vector<int>& cost) {
        if(i > cost.size()-1) return 0;
        if(memo[i] != -1) return memo[i];
        memo[i] = cost[i] + min(foo(i+1, cost), foo(i+2, cost));
        return memo[i];
    }
};