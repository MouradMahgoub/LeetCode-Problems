class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(m*n != original.size()) return ans;
        ans = vector<vector<int>> (m, vector<int> (n));
        int indx = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans[i][j] = original[indx++];
        return ans;
    }
};