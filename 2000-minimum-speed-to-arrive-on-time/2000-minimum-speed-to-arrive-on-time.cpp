class Solution {
public:
    bool good (vector<int>& dist, double hour, int ans) {
        double sum=0;
        for(int i=0; i<dist.size()-1; i++)
            sum += ceil(1.0*dist[i]/ans);
        sum += 1.0*dist[dist.size()-1]/ans;
        return sum <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= int(dist.size())-1) return -1;
        int l=1, r=1e7;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(good(dist, hour, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};