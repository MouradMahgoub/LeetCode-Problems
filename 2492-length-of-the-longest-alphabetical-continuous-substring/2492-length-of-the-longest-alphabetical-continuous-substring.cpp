class Solution {
public:
    int longestContinuousSubstring(string s) {
        int l=0, ans=1;
        for(int r=1; r<s.size(); r++){
            if(s[r] != s[r-1]+1) l=r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};