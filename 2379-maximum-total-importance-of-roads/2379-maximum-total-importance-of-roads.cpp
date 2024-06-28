class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long> rep(n, 0);
        for(auto edge : roads){
            rep[edge[0]]++;
            rep[edge[1]]++;
        }
        sort(rep.begin(), rep.end());
        long ans=0;
        for(int i=1; i<=n; i++)
            ans += rep[i-1]*i;
        return ans;
    }
};