class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0, r=0, used=0, ans=1;
        for(; r<nums.size(); r++){
            while((used & nums[r]) != 0) used ^= nums[l++];
            used |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};