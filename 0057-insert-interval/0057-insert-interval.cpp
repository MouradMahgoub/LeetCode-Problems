class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size(), newStart = newInterval[0], newEnd = newInterval[1];
        int i = 0;
        while(i < n && intervals[i][1] < newStart){
            ans.push_back(intervals[i++]);
        }
        while(i < n && intervals[i][0] <= newEnd){
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            i++;
        }
        ans.push_back(vector<int>{newStart, newEnd});
        while(i < n){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};