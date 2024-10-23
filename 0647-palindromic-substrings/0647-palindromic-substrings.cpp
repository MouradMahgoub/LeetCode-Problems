class Solution {
public:
    int countPalindrome (int l, int r, string s) {
        int cnt = 0;
        while(l >= 0 && r < s.size() && s[l--] == s[r++]){
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans = 0, l, r;
        for(int i=0; i<s.size(); i++){
            //odd
            l = i; r = i;
            ans += countPalindrome(l, r, s);
            //even
            l = i; r = i+1;
            ans += countPalindrome(l, r, s);
        }   
        return ans;
    }
};