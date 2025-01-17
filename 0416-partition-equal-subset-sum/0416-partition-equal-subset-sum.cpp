class Solution {
public:
    vector<vector<int>> memo;

    bool foo (int i, int rem, vector<int>& nums) {
        if(rem == 0) return true;
        if(rem < 0 || i >= nums.size()) return false;
        if(memo[i][rem] != -1) return memo[i][rem];
        return memo[i][rem] = (foo(i+1, rem - nums[i], nums)
            || foo(i+1, rem, nums));
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum&1) return false;
        memo = vector<vector<int>> (nums.size(), vector<int>(sum/2 + 1, -1));
        return foo(0, sum/2, nums);
    }
};

// vector<vector<int>> memo;

//     bool canPartition(vector<int>& nums) {
//         int sum = 0;    
//         for(int i : nums) sum += i;
//         memo = vector<vector<int>>(nums.size(), vector<int>(sum+5, -1));
//         return foo(0, sum, nums);
//     }

//     int foo(int i, int sum, vector<int>& nums){
//         if(sum == 0) return 1;
//         if(sum < 0 || i == nums.size()) return 0;
//         if(memo[i][sum] != -1) return memo[i][sum];
//         return memo[i][sum] = max(foo(i+1, sum-nums[i], nums), foo(i+1, sum, nums));
//     }