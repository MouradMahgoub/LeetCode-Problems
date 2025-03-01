class Solution {
public:
    string add (string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while(s1.size() < s2.size()) s1 += '0';
        while(s2.size() < s1.size()) s2 += '0';
        string ans(s1.size()+1, '0');
        for(int i=0; i<s1.size(); i++){
            int res= (ans[i] - '0') + (s1[i] - '0') + (s2[i] - '0');
            ans[i] = '0' + res%10;
            ans[i+1] = '0' + res/10;
        }
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string s1, string s2) {
        if(s1 == "0" || s2 == "0") return "0";
        string ans = "0";
        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
                int temp = (s1[i] - '0')*(s2[j] - '0');
                string inter = to_string(temp);
                for(int k=0; k< s1.size()-1-i+s2.size()-1-j; k++) inter += '0';
                ans = add(ans, inter);
            }
        }
        return ans;
    }
};