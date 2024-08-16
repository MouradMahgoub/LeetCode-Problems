class Solution {
public:
    int maxDistance(vector<vector<int>>& arrs) {
        vector<pair<int, int>> mins(arrs.size()), maxs(arrs.size());
        for(int i=0; i<arrs.size(); i++){
            mins[i] = {arrs[i][0], i};
            maxs[i] = {arrs[i][arrs[i].size()-1], i};
        }
        sort(mins.begin(), mins.end());
        sort(maxs.rbegin(), maxs.rend());
        int ans=0, i=0;
        while(maxs[0].second == mins[i].second) i++;      
        ans = abs(maxs[0].first - mins[i].first);
        i=0;
        while(mins[0].second == maxs[i].second) i++;      
        ans = max(ans, abs(mins[0].first - maxs[i].first));
        return ans;
    }
};