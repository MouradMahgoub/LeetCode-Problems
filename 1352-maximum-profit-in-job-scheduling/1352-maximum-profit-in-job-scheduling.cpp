class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<pair<int, int>, int>> v(n);
        for(int i=0; i<n; i++){
            v[i] = {{startTime[i], endTime[i]}, profit[i]};
        }
        sort(v.begin(), v.end(), [](const pair<pair<int, int>, int> &a, 
        const pair<pair<int, int>, int> &b) {
            return a.first.second < b.first.second;
        });
        vector<pair<int, int>> dp;
        dp.push_back({0, 0});
        for(auto &[temp, p] : v){
            auto& [s, e] = temp;
            auto it = --upper_bound(dp.begin(), dp.end(), pair<int, int>{s, INT_MAX}, 
            [](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
            int taken = p + it->second;
            int notTaken = dp[dp.size()-1].second;
            if(taken > notTaken) 
                dp.push_back({e, taken});            
        }
        return dp[dp.size()-1].second;
    }
};