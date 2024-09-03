class Solution {
public:
    int getLucky(string s, int k) {
        string numStr;
        for(char c : s)
            numStr += to_string(c - 'a' + 1);
        int ans;
        while(k--){
            ans = 0;
            for(char c : numStr)
                ans += (c - '0');            
            numStr = to_string(ans);
        }
        return ans;
    }
};