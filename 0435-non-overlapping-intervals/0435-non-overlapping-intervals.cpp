class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int nonOverlapping = 1;
        int tempEnd = inter[0][1];
        for(int i=1; i<inter.size(); i++){
            if(tempEnd <= inter[i][0]){
                nonOverlapping++;
                tempEnd = inter[i][1];
            }
        }
        return inter.size() - nonOverlapping;
    }
};