class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return rob(0, nums);
    }
    int rob (int i, vector<int>& nums) {
        if(i > nums.size()-1) return 0;
        if(memo[i] != -1) return memo[i];
        memo[i] = max(nums[i] + rob(i+2, nums), rob(i+1, nums));
        return memo[i]; 
    }
};