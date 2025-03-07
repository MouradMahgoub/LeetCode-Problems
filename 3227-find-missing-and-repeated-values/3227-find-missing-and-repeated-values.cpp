class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int n = grid.size();
        vector<int> ans(2);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(mp[grid[i][j]]) ans[0] = grid[i][j];
                else mp[grid[i][j]]++;
        for(int i=1; i<=n*n; i++)
            if(mp[i] == 0){
                ans[1] = i;
                break;
            }
        return ans;
    }
};