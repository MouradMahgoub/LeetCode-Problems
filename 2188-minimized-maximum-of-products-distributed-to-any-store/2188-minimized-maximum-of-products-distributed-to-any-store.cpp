class Solution {
public:
    bool good (int n, vector<int>& q, int ans) {
        int sum=0;
        for(int& i : q) sum += ceil(1.0*i/ans);
        return sum <= n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1, r=*max_element(q.begin(), q.end());
        while(l < r){
            int mid = l + (r-l)/2;
            if(good(n, q, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};