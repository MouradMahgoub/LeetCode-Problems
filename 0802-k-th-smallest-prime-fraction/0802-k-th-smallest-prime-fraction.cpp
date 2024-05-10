class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> v((arr.size()*(arr.size()-1))/2);
        int indx = 0;
        for(int i=0; i<arr.size(); i++)
            for(int j=i+1; j<arr.size(); j++)
                v[indx++] = {arr[i]*1.0/arr[j], {arr[i], arr[j]}};
        sort(v.begin(), v.end());
        return {v[k-1].second.first, v[k-1].second.second};
    }
};