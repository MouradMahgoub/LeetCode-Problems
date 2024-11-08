class Solution {
public:
    int numDecodings(string s) {
        if(s.size() < 2) return s.size() && s[0] != '0' ? 1 : 0;
        vector<int> dp(s.size(), 0);
        dp[0] = (s[0] == '0' ? 0 : 1);
        if(s[1] != '0')
            dp[1] = dp[0];
        if(stoi(s.substr(0, 2)) > 9 && stoi(s.substr(0, 2)) < 27)
            dp[1]++;
        for(int i=2; i<s.size(); i++){
            if(s[i] != '0') 
                dp[i] += dp[i-1];
            if(stoi(s.substr(i-1, 2)) > 9 && stoi(s.substr(i-1, 2)) < 27)
                dp[i] += dp[i-2];
            if(dp[i] == 0) break;
        }
        return dp[s.size()-1];
    }
};
    // vector<int> memo;
    // int foo (int i, string s) {
    //     if(i > s.size()-1) return 1;
    //     if(memo[i] != -1) return memo[i];
    //     int ans = 0;
    //     if(s[i] != '0')
    //         ans += foo(i+1, s);
    //     if(i < s.size()-1 && stoi(s.substr(i, 2)) > 9 && stoi(s.substr(i, 2)) < 27)
    //         ans += foo(i+2, s);
    //     return memo[i] = ans;
    // }

        // memo = vector<int>(s.size(), -1);
        // return foo(0, s);
        