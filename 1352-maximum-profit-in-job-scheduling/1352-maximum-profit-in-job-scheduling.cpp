class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(), maxEndTime = 0;
        vector<pair<pair<int, int>, int>> v(n);
        for(int i=0; i<n; i++){
            v[i] = {{startTime[i], endTime[i]}, profit[i]};
            maxEndTime = max(maxEndTime, endTime[i]);
        }
        sort(v.begin(), v.end(), [](const pair<pair<int, int>, int> &a, 
        const pair<pair<int, int>, int> &b) {
            return a.first.second < b.first.second;
        });
        vector<pair<int, int>> dp;
        dp.push_back({0, 0});
        for(auto &[temp, p] : v){
            auto &[s, e] = temp;
            int taken = p;
            for(int i=dp.size()-1; i>=0; i--)
                if(dp[i].first <= s){
                    taken += dp[i].second;
                    break;
                }
            //*lower_bound(dp.begin(), dp.end(), s);
            int notTaken = dp[dp.size()-1].second;
            if(taken > notTaken) 
                dp.push_back({e, taken});            
        }
        return dp[dp.size()-1].second;
    }
};