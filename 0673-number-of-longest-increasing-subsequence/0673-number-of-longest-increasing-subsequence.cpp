class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp1(nums.size(), 1), dp2(nums.size(), 1);
        int mx=1;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(dp1[i] < dp1[j]+1) dp2[i]=dp2[j];
                    else if(dp1[i] == dp1[j]+1) dp2[i] += dp2[j];
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
            mx = max(mx, dp1[i]);
        }
        int ans=0;
        for(int i=0; i<nums.size(); i++)
            if(dp1[i] == mx) ans += dp2[i];
        return ans;
    }
};