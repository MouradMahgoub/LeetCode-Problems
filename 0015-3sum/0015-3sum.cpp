class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> setAns;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int newTarget = -nums[i];
            int l=i+1, r=n-1;
            while(l < r){
                if((long)nums[l] + (long)nums[r] < newTarget) l++;
                else if((long)nums[l] + (long)nums[r] > newTarget) r--;
                else setAns.insert({nums[i], nums[l++], nums[r--]});
            }
        }
        vector<vector<int>> ans;
        for(auto v : setAns) ans.push_back(v);
        return ans;
    }
};