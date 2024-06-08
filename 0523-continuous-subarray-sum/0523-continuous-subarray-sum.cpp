class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int curr = 0; mp[0] = -1;
        for(int i=0; i<nums.size(); i++){
            curr = (curr+nums[i])%k;
            if(mp.find(curr) == mp.end()){
                mp[curr] = i;
            }else{
                if(i - mp[curr] > 1) return true;
            }
        }
        return false;
    }
};