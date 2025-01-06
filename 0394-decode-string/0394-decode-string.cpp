class Solution {
public:
    string decodeString(string s) {
        stack<int> stNum;
        stack<string> stStr;
        stNum.push(1);
        stStr.push("");
        int i = 0;
        while(i < s.size()) {
            if(isdigit(s[i])){
                int  k = 0;
                while(isdigit(s[i])){
                    k = k*10 + (s[i] - '0');
                    i++;
                }
                stNum.push(k);
                stStr.push("");
                i++; // skip '['
            }
            if(isalpha(s[i])) {
                string temp = stStr.top(); stStr.pop();
                while(isalpha(s[i])) {
                    temp += s[i];
                    i++;
                }
                stStr.push(temp);
            }
            if(s[i] == ']') {
                int k = stNum.top(); stNum.pop();
                string temp = "";
                while(k--) temp += stStr.top();
                stStr.pop();
                string prfxStr = stStr.top(); stStr.pop();
                stStr.push(prfxStr + temp);
                i++;
            }
        }
        return stStr.top();
    }
};