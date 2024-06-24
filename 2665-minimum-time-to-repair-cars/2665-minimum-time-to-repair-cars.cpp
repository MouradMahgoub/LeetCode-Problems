class Solution {
public:
    bool good (vector<int>& ranks, int cars, long ans) {
        long sum = 0;
        for(int r : ranks) sum += (long)sqrt(1.0*ans/r);
        return sum >= cars;
    } 
    long long repairCars(vector<int>& ranks, int cars) {
        long l=0, r=1e18;
        while(l < r){
            long mid = l + (r-l)/2;
            if(good(ranks, cars, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};