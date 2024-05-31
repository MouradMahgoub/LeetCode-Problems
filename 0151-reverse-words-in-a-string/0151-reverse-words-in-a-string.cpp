class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = s.size()-1;
        while(l <= s.size()-1 && s[l] == ' ') l++;
        while(r >= 0 && s[r] == ' ') r--;
        string temp = "", ans = "";
        for(int i=l; i<=r; i++){
            while(i <= r && s[i] != ' ') temp += s[i++];
            if(temp.size()) ans = temp + " " + ans;
            temp = "";
        }
        ans.erase(ans.size()-1, 1);
        return ans;
    }
};