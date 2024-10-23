class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1], nums[0]);
        return max(rob(0, nums.size()-2, nums), rob(1, nums.size()-1, nums));
    }
    int rob (int start, int end, vector<int>& nums) {
        // if(start > end) return nums[0];
        // if(start == end) return nums[start];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i=start+2; i<=end; i++)
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        return dp[end];
    }
};