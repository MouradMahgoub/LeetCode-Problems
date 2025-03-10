class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zs = 0, ans = 0;
        for(int l=0, r=0; r<n; r++){
            if(!nums[r]) zs++;
            while(zs > 1){
                if(!nums[l]) zs--;
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};