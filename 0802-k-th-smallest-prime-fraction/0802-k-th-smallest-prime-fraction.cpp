class Solution {
public:
    Solution () {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> minpq;
        for(int i=0; i<arr.size(); i++)
            for(int j=i+1; j<arr.size(); j++)
                minpq.push({arr[i]*1.0/arr[j], {arr[i], arr[j]}});
        vector<int> ans(2);
        while(k--){
            auto p = minpq.top();
            ans = {p.second.first, p.second.second};
            minpq.pop();
        }
        return ans;
    }
};