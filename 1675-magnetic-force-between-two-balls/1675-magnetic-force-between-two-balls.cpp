class Solution {
public:
    bool good (vector<int>& v, int m, int ans) {
        int curr = *v.begin();
        m--;
        while(m--){
            auto it = lower_bound(v.begin(), v.end(), curr + ans);
            if(it == v.end()) return false;
            curr = *it;
        }
        return true;
    }
    int maxDistance(vector<int>& v, int m) {
        sort(v.begin(), v.end());
        int l=1, r=1e9;
        while(l < r) {
            int mid = l + (r-l+1)/2;
            if(good(v, m, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};