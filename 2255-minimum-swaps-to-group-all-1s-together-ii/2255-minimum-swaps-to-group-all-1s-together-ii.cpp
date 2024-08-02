class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int tot1s = 0, curr1s=0;
        for(int i : nums) if(i) tot1s++;
        for(int i=0; i<tot1s; i++) if(nums[i]) curr1s++;
        int ans=1e9;
        for(int l=0, r=tot1s-1; l<nums.size(); ){
            ans = min(ans, tot1s - curr1s);
            curr1s -= nums[l++];
            curr1s += nums[(++r)%(nums.size())];
        }
        return ans;
    }
};