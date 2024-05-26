class Solution {
public:
    long long foo (int i, int k, int isEven, vector<int>& nums, vector<vector<long>>& memo) {
        if(i == nums.size()) return isEven ? 0 : INT_MIN;
        if(memo[i][isEven] != -1) return memo[i][isEven];
        long long with_xor = (nums[i]^k) + foo(i+1, k, isEven^1, nums, memo); 
        long long without_xor = nums[i] + foo(i+1, k, isEven, nums, memo); 
        return memo[i][isEven] = max(with_xor, without_xor);
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<long>> memo(nums.size(), vector<long>(2, -1));
        return foo(0, k, 1, nums, memo);
    }
};
        // long long ans = 0;
        // int cnt = 0, minDiff = INT_MAX;
        // for(int num : nums){
        //     int xorNum = num^k;
        //     if(xorNum > num) cnt++;
        //     ans += max(num, xorNum);
        //     minDiff = min(minDiff, abs(num - xorNum));
        // }
        // return cnt&1 ? ans - minDiff : ans;