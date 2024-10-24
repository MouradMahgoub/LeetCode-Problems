class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        vector<vector<int>> ans;
        ans.push_back(inter[0]);
        for(int i=1; i<inter.size(); i++){
            int currEnd = ans[ans.size()-1][1];
            int newStart = inter[i][0], newEnd = inter[i][1];
            if(currEnd >= newStart)
                ans[ans.size()-1][1] = max(currEnd, newEnd);
            else
                ans.push_back(inter[i]);
        }
        return ans;
    }
};