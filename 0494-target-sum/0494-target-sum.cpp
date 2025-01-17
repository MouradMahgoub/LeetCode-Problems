class Solution {
public:
    map<pair<int, int>, int> memo;

    int foo (int i, int currSum, int target, vector<int>& nums) {
        if(i == nums.size()) return currSum == target ? 1 : 0;
        if(memo.find({i, currSum}) != memo.end()) return memo[{i, currSum}];
        return memo[{i, currSum}] = foo(i+1, currSum + nums[i], target, nums) +
                                  foo(i+1, currSum - nums[i], target, nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return foo(0, 0, target, nums);
    }
};