class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> ans(n, INT_MAX);
        ans[src] = 0;
        for(int i=0; i<k+1; i++){
            vector<int> temp(ans);
            for(auto f : flights){
                if(ans[f[0]] == INT_MAX) continue;
                temp[f[1]] = min(temp[f[1]], ans[f[0]] + f[2]);
            }
            ans = temp;
        }
        return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};