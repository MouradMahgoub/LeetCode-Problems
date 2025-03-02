class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        map<int, int> mp;
        for(auto v : v1) mp[v[0]] = v[1];
        for(auto v : v2) mp[v[0]] += v[1];
        vector<vector<int>> ans;
        for(auto it : mp) ans.push_back({it.first, it.second});
        return ans;
    }
};