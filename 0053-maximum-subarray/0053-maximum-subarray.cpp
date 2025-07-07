class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= INT_MIN, curr = 0;
        for(int num : nums){
            curr = max(num, curr+num);
            ans= max(ans, curr);
        }
        return ans;
    }
};