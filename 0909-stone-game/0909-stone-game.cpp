class Solution {
public:
    int memo[505][505];
    int foo(int l, int r, vector<int>& piles) {
        if(l > r) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        memo[l][r] = max( piles[l] + min(foo(l+2, r, piles), foo(l+1, r-1, piles)), 
                          piles[r] + min(foo(l+1, r-1, piles), foo(l, r-2, piles))
                        );
        return memo[l][r];
    } 

    bool stoneGame(vector<int>& piles) {
        memset(memo, -1, sizeof(memo));
        int sum = 0;
        for(int i : piles) sum += i;
        return foo(0, piles.size()-1, piles) > sum/2;
    }
};