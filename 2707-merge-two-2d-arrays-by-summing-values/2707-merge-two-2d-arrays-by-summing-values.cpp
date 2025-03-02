class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < v1.size() && j < v2.size()){
            if(v1[i][0] < v2[j][0]){
                ans.push_back({v1[i++]});
            }else if(v1[i][0] > v2[j][0]){
                ans.push_back({v2[j++]});
            }else{
                ans.push_back({v1[i][0], v1[i++][1] + v2[j++][1]});
            }
        }
        while(i < v1.size()) ans.push_back(v1[i++]);
        while(j < v2.size()) ans.push_back(v2[j++]);
        return ans;
    }
};
        // map<int, int> mp;
        // for(auto v : v1) mp[v[0]] = v[1];
        // for(auto v : v2) mp[v[0]] += v[1];
        // vector<vector<int>> ans;
        // for(auto it : mp) ans.push_back({it.first, it.second});
        // return ans;