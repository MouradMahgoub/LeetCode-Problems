class Solution {
public:
    vector<int> dp;

    int dfs (vector<int>& nums, int target) {
        if(target <= 0) return target == 0;
        if(dp[target] != -1) return dp[target];
        
        dp[target] = 0;
        for(int i=0; i<nums.size(); i++){
            dp[target] += dfs(nums, target-nums[i]);
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int>(1000+5, -1);
        return dfs(nums, target);
    }
};