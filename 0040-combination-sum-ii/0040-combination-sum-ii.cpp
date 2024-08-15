class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void dfs(int i, int sum, int target, vector<int>& candidates) {
        if(sum == target) ans.push_back(curr);
        if(i > candidates.size()-1 || sum >= target) return;
        //include
        curr.push_back(candidates[i]);
        dfs(i+1, sum+candidates[i], target, candidates);
        curr.pop_back();
        //not including
        int it = upper_bound(candidates.begin(), candidates.end(), candidates[i]) - candidates.begin();
        // while(i < candidates.size()-1 && candidates[i] == candidates[i+1]) i++;
        dfs(it, sum, target, candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, target, candidates);
        return ans;
    }
};