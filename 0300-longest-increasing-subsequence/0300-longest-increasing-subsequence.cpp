class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i=1; i<nums.size(); i++)
            for(int j=i-1; j>=0; j--)
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
        int ans = 0;
        for(int i : dp) ans = max(ans, i);
        vector<int> lis;
        int cnt = ans;
        for(int i=nums.size()-1; i>=0 && cnt > 0; i--)
            if(dp[i] == cnt){
                lis.push_back(nums[i]);
                cnt--;
            }
        reverse(lis.begin(), lis.end());
        for(int i : lis) cout << i << " ";
        return ans;
    }
};
