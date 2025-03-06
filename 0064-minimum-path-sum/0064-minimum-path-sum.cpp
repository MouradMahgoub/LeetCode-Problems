class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        for(int j=1; j<m; j++) g[0][j] += g[0][j-1];
        for(int i=1; i<n; i++) g[i][0] += g[i-1][0];
        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++)
                g[i][j] += min(g[i-1][j], g[i][j-1]);
        return g[n-1][m-1];
    }
};