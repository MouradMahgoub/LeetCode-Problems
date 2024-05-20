class Solution {
public:
    int foo (vector<int>& nums, int i, int temp) {
        if(i == nums.size()) return temp;
        int a = foo(nums, i+1, temp);
        int b = foo(nums, i+1, temp ^= nums[i]);
        return a + b;
    }
    int subsetXORSum(vector<int>& nums) {
        return foo(nums, 0, 0);
    }
};