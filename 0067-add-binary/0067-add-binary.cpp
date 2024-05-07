class Solution {
public:
    string addBinary(string a, string b) {
        int diff = abs((int)(a.size() - b.size()));
        if(a.size() > b.size()) while(diff--) b = "0"+b;
        else while(diff--) a = "0"+a;
        string ans(a.size(), '0');
        int carry = 0;
        for(int i=a.size()-1; i>=0; i--){
            ans[i] = (((a[i] - '0') + (b[i] - '0') + carry)%2 ? '1' : '0');
            carry = ((a[i] - '0') + (b[i] - '0') + carry)/2;
            cout << a << " " << b << " " << ans << "\n";
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
};