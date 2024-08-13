class Solution {
public:
    int target, n;
    vector<int> candidates;
    set<vector<int>> ans;

    void foo(int i, int sum, vector<int> temp) {
        if(sum == target) ans.insert(temp);
        if(sum >= target) return;
        for(int j=i; j<n; j++){
            temp.push_back(candidates[j]);
            foo(j, sum+candidates[j], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        this->n = candidates.size();
        for(int i=0; i<n; i++) foo(i, 0, {});
        vector<vector<int>> ans2(ans.begin(), ans.end());
        return ans2;
    }
};