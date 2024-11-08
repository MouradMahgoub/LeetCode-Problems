class Solution {
public:
    vector<vector<int>> memo;
    int foo(int i, int amount, vector<int>& coins) {
        if(amount == 0) return 0;
        if(amount < 0 || i == coins.size()) return 1e9;
        if(memo[i][amount] != -1) return memo[i][amount];
        return  memo[i][amount] = 
                    min(0 + foo(i+1, amount, coins),
                        min(1 + foo(i, amount - coins[i], coins),
                        1 + foo(i+1, amount - coins[i], coins))
                    );
    }
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));
        int ans = foo(0, amount, coins);
        return ans == 1e9 ? -1 : ans;
    }
};