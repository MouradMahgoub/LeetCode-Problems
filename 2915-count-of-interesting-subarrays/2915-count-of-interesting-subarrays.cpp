class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long prfx = 0,  ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++) nums[i] = (nums[i]%modulo == k);
        for(int i=0; i<nums.size(); i++){
            prfx += nums[i];
            int curr = prfx%modulo;
            int need = (curr - k + modulo)%modulo;
            ans += mp[need];
            mp[curr]++;
        }
        return ans;
    }
};