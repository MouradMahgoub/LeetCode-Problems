class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1;    
        int carry = 0;
        string ans = "";
        while(i >= 0 || j >= 0 || carry){
            int d1 = (i >= 0 ? num1[i] - '0' : 0);
            int d2 = (j >= 0 ? num2[j] - '0' : 0);
            int res = d1 + d2 + carry;
            ans += char('0' + res%10);
            carry = res/10;
            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
