class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto edge : edges){
            mp[edge[0]]++;
            mp[edge[1]]++;
        }
        int ans = 1;
        for(auto [node, degree] : mp)
            if(degree == (int)edges.size()) ans = node;
        return ans;
    }
};