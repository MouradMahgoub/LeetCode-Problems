class Solution {
public:
    string foo(int n){
        if(n == 1) return "1";
        string temp = foo(n-1);
        string ans = "";
        int i = 0;
        while(i < temp.size()){
            char curr = temp[i];
            int cnt = 0;
            while(i < temp.size() && temp[i] == curr) {
                cnt++;
                i++;
            }
            ans += to_string(cnt);
            ans += curr;
        }
        return ans;
    }
    string countAndSay(int n) {
        return foo(n);
    }
};