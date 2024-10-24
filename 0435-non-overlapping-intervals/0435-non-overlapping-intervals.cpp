class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        int prevStart = inter[0][0], prevEnd = inter[0][1];
        int cnt = 0;
        for(int i=1; i<inter.size(); i++){
            int currStart = inter[i][0], currEnd = inter[i][1];
            if(prevEnd > currStart){
                cnt++;
                if(prevEnd > currEnd){
                    prevStart = currStart;
                    prevEnd = currEnd;
                }
            }else{
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return cnt;
    }
};