class Solution {
public:

    string add (string s1, string s2) {
        int i = s1.size()-1, j = s2.size()-1;
        int carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry){
            int d1 = (i >= 0 ? s1[i] - '0' : 0);
            int d2 = (j >= 0 ? s2[j] - '0' : 0);
            int res = d1 + d2 + carry;
            ans.push_back('0' + res%10);
            carry = res/10;
            i--; j--;
        }
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