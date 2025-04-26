class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int ans = 0;
        for(auto v : grid) mp[v]++;
        for(int j=0; j<grid[0].size(); j++){
            vector<int> v;
            for(int i=0; i<grid.size(); i++){
                v.push_back(grid[i][j]);
            }
            ans += mp[v]; 
        }
        return ans;
    }
};