class Solution {
public:
    bool good (vector<int>& w, int days, int ans) {
        int sum=0, cnt=0;
        for(int i=0; i<w.size(); i++){
            sum += w[i];
            if(sum > ans) {
                cnt++;
                sum = w[i];
            } 
        }
        if(sum) cnt++;
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int l = *max_element(w.begin(), w.end()), r = 1e9;
        while(l < r){
            int mid = l + (r-l)/2;
            if(good(w, days, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};