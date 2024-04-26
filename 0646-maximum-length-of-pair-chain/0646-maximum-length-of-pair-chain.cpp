class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
          int ans=1;
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end());
        for(int i=0; i<pairs.size(); i++)
            for(int j=0; j<i; j++)
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans, dp[i]);
                }
        return ans;
    }
};