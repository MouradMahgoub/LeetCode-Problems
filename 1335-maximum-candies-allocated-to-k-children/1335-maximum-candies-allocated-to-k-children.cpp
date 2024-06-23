class Solution {
public:
    bool good (vector<int>& candies, long long k, int ans) {
        if(ans == 0) return true;
        long sum=0;
        for(int i : candies) sum += i/ans;
        return sum >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=0, r= 1e9;
        int ans = 0 ;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(good(candies, k, mid)){
                l = mid + 1;
                ans = max(ans, mid);
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};