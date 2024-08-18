class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs (int i, vector<int>& nums) {
        // if(len == k) 
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        } 

        // for(int i=indx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i+1, nums);
            temp.pop_back();

            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            dfs(i+1, nums);
        // }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for(int k=0; k<=nums.size(); k++)
        dfs(0, nums);
        return ans;
    }
};