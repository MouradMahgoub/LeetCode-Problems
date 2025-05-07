class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0,currIndx = 0;
        while(i < n){
            int cnt = 1;
            while(i + cnt < n &&  chars[i] == chars[i + cnt]) cnt++;
            chars[currIndx++] = chars[i];
            if(cnt > 1) for(char c : to_string(cnt)) chars[currIndx++] = c;
            i += cnt;
        }
        return currIndx;
    }
};