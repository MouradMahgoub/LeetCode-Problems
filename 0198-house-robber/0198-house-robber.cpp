class Solution {
public:
    vector<int> memo;
    int foo(vector<int>& nums, int i){
        if(i > nums.size()-1) return 0 ;
        if(memo[i] != -1) return memo[i];
        return memo[i] = max(nums[i] + foo(nums, i+2), foo(nums, i+1));
    }
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return foo(nums, 0);
    }
};
        // int prev1 = 0, prev2=0;
        // for(int num : nums){
        //     int temp = prev1;
        //     prev1 = max(prev2 + num, prev1);
        //     prev2 = temp;
        // }
        // return prev1;
        
        // vector<int> dp(nums.size()+1, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for(int i=2; i<nums.size(); i++)
        //     dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        // return dp[nums.size()-1];
    // vector<int> memo;
    // int rob(vector<int>& nums) {
        // memo = vector<int>(nums.size(), -1);
        // return rob(0, nums);
    // }
    // int rob (int i, vector<int>& nums) {
    //     if(i > nums.size()-1) return 0;
    //     if(memo[i] != -1) return memo[i];
    //     memo[i] = max(nums[i] + rob(i+2, nums), rob(i+1, nums));
    //     return memo[i]; 
    // }