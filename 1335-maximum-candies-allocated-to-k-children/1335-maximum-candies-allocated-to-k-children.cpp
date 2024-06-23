class Solution {
public:
    bool good (vector<int>& candies, long long k, int ans) {
        if(ans == 0) return true;
        long sum=0;
        for(int i : candies) sum += i/ans;
        return sum >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=0, r= 1e7;
        int ans = 0 ;
        while(l < r){
            int mid = l + (r-l+1)/2;
            if(good(candies, k, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};