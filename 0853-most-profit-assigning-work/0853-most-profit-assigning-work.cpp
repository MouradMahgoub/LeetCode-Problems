class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v(profit.size());
        for(int i=0; i<profit.size(); i++)
            v[i] = {profit[i], difficulty[i]};
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        sort(worker.begin(), worker.end(), greater<int>());
        int ans = 0, w = 0, d = 0;
        while(w < worker.size() && d < v.size()){
            if(worker[w] >= v[d].second){
                ans += v[d].first;
                w++;                
            }else{
                d++;
            }
        }
        return ans;
    }
};