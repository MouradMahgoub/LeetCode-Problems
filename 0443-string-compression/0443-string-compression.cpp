class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0,currIndx = 0;
        while(i < n){
            int cnt = 0;
            int j = i;
            while(j<n && chars[i] == chars[j]) j++, cnt++;
            if(cnt == 1) chars[currIndx++] = chars[i];
            else {
                chars[currIndx++] = chars[i];
                string s = to_string(cnt);
                for(char c : s) chars[currIndx++] = c;
            }
            i = j;
        }
        return currIndx;
    }
};