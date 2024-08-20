class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> mp (1e6+5, 0);
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                mp[abs(nums[j] - nums[i])]++;
            }
        }
        int ans=0;
        for(int i=0; i<1e6+5; i++){
            ans = i;
            k -= mp[i];
            if(k <= 0) return ans;
        }
        return -1;
    }
};