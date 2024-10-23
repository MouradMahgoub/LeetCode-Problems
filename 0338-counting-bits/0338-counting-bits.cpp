class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        int offset = 1;
        for(int i=1; i<=n; i++){
            if(offset*2 == i)
                offset = i;
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }
};
    // int countOnes (int x) {
    //     int cnt = 0;
    //     while(x != 0){
    //         cnt += (x&1 == 1);
    //         x >>= 1;
    //     }
    //     return cnt;
    // }
        // vector<int> ans(n+1);
        // for(int i=0; i<=n; i++)
        //     ans[i] = countOnes(i);
        // return ans;