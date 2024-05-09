class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxJumb=nums[0];
        for (int i=1; i<nums.size(); i++) {
            mxJumb--;
            if(mxJumb < 0) return false;
            mxJumb = max(mxJumb, nums[i]);
        }
        return true;   
    }
};