class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l=i+1, r=n-1;
            while(l < r){
                long three_sum = (long)nums[i] + (long)nums[l] + (long)nums[r];
                if(three_sum < 0) l++;
                else if(three_sum > 0) r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return ans;
    }
};