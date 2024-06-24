class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int l=0, r=0, ts=0, fs=0, ans=1;
        for(; r<s.size(); r++){
            if(s[r] == 'T') ts++;
            else fs++;
            while(min(ts, fs) > k){
                if(s[l] == 'T') ts--;
                else fs--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};