class Solution {
public:
    vector<vector<int>> memo;
    int totalSum; 

    int foo (int i, int currSum, int target, vector<int>& nums) {
        if(i == nums.size()) return currSum == target ? 1 : 0;
        if(memo[i][totalSum + currSum] != -1) return memo[i][totalSum + currSum];
        return memo[i][totalSum + currSum] = foo(i+1, currSum + nums[i], target, nums) +
                                  foo(i+1, currSum - nums[i], target, nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        memo = vector<vector<int>> (nums.size(), vector<int>(2*totalSum + 1, -1));
        return foo(0, 0, target, nums);
    }
};