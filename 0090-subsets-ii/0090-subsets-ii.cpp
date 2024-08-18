class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs (int indx, int len, int k, vector<int>& nums) {
        if(len == k) ans.push_back(temp);
        if(len >= k) return;
        for(int i=indx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i+1, len+1, k, nums);
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int k=0; k<=nums.size(); k++)
            dfs(0, 0, k, nums);
        return ans;
    }
};