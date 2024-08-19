class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp, visited;

    void dfs (vector<int>& nums) {
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = 1;
            temp.push_back(nums[i]);
            dfs(nums);
            temp.pop_back();
            visited[i] = 0;
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        visited.assign(nums.size(), 0);
        dfs(nums);
        return ans;
    }
};