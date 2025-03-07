class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
        auto it1 = lower_bound(v.begin(), v.end(), x);
        auto it2 = upper_bound(v.begin(), v.end(), x);
        if(it1 - it2 == 0) return {-1, -1};
        return {int(it1 - v.begin()), int(it2 - v.begin() - 1)};
    }
};