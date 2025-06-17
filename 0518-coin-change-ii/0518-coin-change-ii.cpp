class Solution {
public:
    vector<vector<int>> memo;
    int foo(int indx, int target, vector<int>& coins) {
        if(target == 0) return 1;
        if(target < 0 || indx == coins.size()) return 0;
        if(memo[indx][target] != -1) return memo[indx][target];
        return memo[indx][target] = foo(indx, target - coins[indx], coins)
                                    + foo(indx+1, target, coins);
    }

    int change(int amount, vector<int>& coins) {
        memo = vector<vector<int>>(coins.size(), vector<int> (amount+1, -1));
        return foo(0, amount, coins);
    }
};