class Solution {
public:
    bool good (vector<int>& v, int m, int k, int ans) {
        int cnt=0, sum=0;
        for(int i=0; i<v.size(); i++){
            if(v[i] - ans <= 0)
                sum++;
            else
                sum=0;
            if(sum == k){
                cnt++;
                sum=0;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int>& v, int m, int k) {
        if((long)v.size() < (long)m*k) return -1;
        int l= *min_element(v.begin(), v.end()), r= *max_element(v.begin(), v.end()); 
        cout << l << " " << r << " ";
        while(l < r){
            int mid = l + (r-l)/2;
            if(good(v, m, k, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}; 