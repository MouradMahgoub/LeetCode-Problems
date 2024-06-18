class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &i : nums) mp[i]++;
        int ans=0, mx = *max_element(nums.begin(), nums.end());
        for(int i=0; i<mx+nums.size(); i++){
            if(mp[i] > 1){
                int duplicates = mp[i] - 1;
                mp[i] = 1;
                mp[i+1] += duplicates;
                ans += duplicates;
            }
        }
        return ans;
    }
};
        // int ans=0;
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i] <= nums[i-1]){
        //         ans += nums[i-1] - nums[i] + 1;
        //         nums[i] = nums[i-1]+1;
        //     }
        // }