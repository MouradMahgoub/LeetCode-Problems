class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i=0; i<arr.size(); i++)
            for(int j=i+1; j<arr.size(); j++){
                pq.push({1.0*arr[i]/arr[j], {arr[i], arr[j]}});
                if(pq.size() > k) pq.pop();
            }
        return {pq.top().second.first, pq.top().second.second};
    }
};
// vector<pair<double, pair<int, int>>> v((arr.size()*(arr.size()-1))/2);
// int indx = 0;
// sort(v.begin(), v.end());


// priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> minpq;
        // vector<int> ans(2);
        // while(k--){
        //     auto p = minpq.top();
        //     ans = {p.second.first, p.second.second};
        //     minpq.pop();
        // }
        // return ans;