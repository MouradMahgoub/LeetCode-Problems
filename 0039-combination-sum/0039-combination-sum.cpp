class Solution {
public:
    int target, n;
    vector<int> candidates;
    vector<vector<int>> ans;

    void foo(int i, int sum, vector<int> temp) {
        if(sum == target) ans.push_back(temp);
        if(sum >= target || i >= n) return;

            foo(i+1, sum, temp);

            temp.push_back(candidates[i]);
            foo(i, sum+candidates[i], temp);
            temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        this->n = candidates.size();
        foo(0, 0, {});
        return ans;
    }
};