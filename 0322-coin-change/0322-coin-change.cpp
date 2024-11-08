class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int currAmount=1; currAmount<=amount; currAmount++)
            for(int coin : coins)
                if(currAmount - coin >= 0)
                    dp[currAmount] = min(dp[currAmount], 1 + dp[currAmount - coin]);
                else break;
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
    // vector<vector<int>> memo;
    // int foo(int i, int amount, vector<int>& coins) {
    //     if(amount == 0) return 0;
    //     if(amount < 0 || i == coins.size()) return 1e9;
    //     if(memo[i][amount] != -1) return memo[i][amount];
    //     return  memo[i][amount] = 
    //                 min(0 + foo(i+1, amount, coins),
    //                     min(1 + foo(i, amount - coins[i], coins),
    //                     1 + foo(i+1, amount - coins[i], coins))
    //                 );
    // }
        // memo = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));
        // int ans = foo(0, amount, coins);
        // return ans == 1e9 ? -1 : ans;