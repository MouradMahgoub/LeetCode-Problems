class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;
        int ans = 0;
        for(int num : nums) {
            if(k == num*2) ans += mp[num]/2;
            else ans += min(mp[num], mp[k - num]);
            mp[num] = 0; mp[k - num] = 0;
        }
        return ans;
    }
};