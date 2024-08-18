class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seen(n, false);
        int ans=0;
        for(long i=2; i<n; i++){
            if(!seen[i]){
                ans++;
                for(long j=i*i; j<n; j+=i)
                    seen[j] = true;
            }
        }     
        return ans;
    }
};