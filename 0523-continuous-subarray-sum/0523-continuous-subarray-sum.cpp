class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int curr = 0;
        for(int i=1; i<=nums.size(); i++){
            curr = (curr+nums[i-1])%k;
            if(curr != 0 && mp[curr] == 0){
                mp[curr] = i;
            }else{
                if(i - mp[curr] > 1) return true;
            }
        }
        return false;
    }
};