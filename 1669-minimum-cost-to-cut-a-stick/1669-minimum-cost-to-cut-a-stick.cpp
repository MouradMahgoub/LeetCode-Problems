class Solution {
public:
    vector<vector<int>> memo;
    int minCost(int n, vector<int>& cuts) {
        memo = vector<vector<int>>(100+5, vector<int>(100+5, -1));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return foo(0, cuts.size()-1, cuts);
    }

    int foo(int start, int end, vector<int>& cuts) {
        if(start - end == 1) return 0;
        if(memo[start][end] != -1) return memo[start][end];
        int ans = 1e9;
        for(int i=start+1; i<end; i++){
            ans = min(ans,
                cuts[end]-cuts[start] + foo(start, i, cuts) + foo(i, end, cuts));
        }
        return memo[start][end] = (ans == 1e9 ? 0 : ans);
    }

};