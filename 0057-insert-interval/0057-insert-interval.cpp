class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) {
        vector<vector<int>> ans;
        int i=0, n=inter.size();
        int newStart = newInter[0], newEnd = newInter[1];
        //no overlap
        while(i < n && newStart > inter[i][1]){
            ans.push_back(inter[i++]);
        }
        //overlaping
        while(i < n && newEnd >= inter[i][0]){
            newStart = min(newStart, inter[i][0]);
            newEnd = max(newEnd, inter[i][1]);
            i++;
        }
        ans.push_back({newStart, newEnd});
        //add rem
        while(i < n){
            ans.push_back(inter[i++]);
        }
        return ans;
    }
};
        // vector<vector<int>> ans;
        // int n = intervals.size(), newStart = newInterval[0], newEnd = newInterval[1];
        // int i = 0;
        // while(i < n && intervals[i][1] < newStart){
        //     ans.push_back(intervals[i++]);
        // }
        // while(i < n && intervals[i][0] <= newEnd){
        //     newStart = min(newStart, intervals[i][0]);
        //     newEnd = max(newEnd, intervals[i][1]);
        //     i++;
        // }
        // ans.push_back(vector<int>{newStart, newEnd});
        // while(i < n){
        //     ans.push_back(intervals[i++]);
        // }
        // return ans;