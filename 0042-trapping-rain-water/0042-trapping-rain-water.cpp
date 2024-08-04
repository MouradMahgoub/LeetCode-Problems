class Solution {
public:
    int trap(vector<int>& v) {
        int ans=0, n=v.size();
        int l=0, r=n-1;
        int maxl=v[0], maxr=v[n-1];
        while(l < r){
            if(maxl < maxr){
                maxl = max(maxl, v[++l]);
                ans += max(0, min(maxl, maxr)-v[l]);                
            }else{
                maxr = max(maxr, v[--r]);
                ans += max(0, min(maxl, maxr)-v[r]);                
            }
        }
        return ans;
    }
};