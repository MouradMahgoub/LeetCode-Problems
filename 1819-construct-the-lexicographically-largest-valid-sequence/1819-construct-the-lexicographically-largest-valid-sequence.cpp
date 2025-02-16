class Solution {
public:
    vector<int> dfs(vector<int> &ans, vector<bool>& used, int pos) {
        if(pos == ans.size()) return ans;
        if(ans[pos] != 0) return dfs(ans, used, pos+1);
        for(int num = used.size()-1; num >= 1; num--) {
            int dist = num == 1 ? 0 : num;
            if(!used[num] && pos + dist < ans.size() && ans[pos + dist] == 0){
                ans[pos] = ans[pos + dist] = num;
                used[num] = true;
                auto res = dfs(ans, used, pos+1);
                if(!res.empty()) return res;
                ans[pos] = ans[pos + dist] = 0;
                used[num] = false;;
            }
        }
        return {};
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n*2 - 1, 0);
        vector<bool> used(n+1, 0);
        return dfs(ans, used, 0);
    }
};