class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs (int indx, int len, vector<int>& nums) {
        // if(len == k) 
        if(len > nums.size()) return;
        ans.push_back(temp);
        for(int i=indx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i+1, len+1, nums);
            temp.pop_back();
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for(int k=0; k<=nums.size(); k++)
            dfs(0, 0, nums);
        return ans;
    }
};