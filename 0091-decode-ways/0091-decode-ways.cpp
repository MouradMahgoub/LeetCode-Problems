class Solution {
public:

    vector<int> memo;

    int foo (int i, string s) {
        if(i > s.size()-1) return 1;
        if(memo[i] != -1) return memo[i];
        int ans = 0;
        if(s[i] != '0')
            ans += foo(i+1, s);
        if(i < s.size()-1 && stoi(s.substr(i, 2)) > 9 && stoi(s.substr(i, 2)) < 27)
            ans += foo(i+2, s);
        return memo[i] = ans;
    }

    int numDecodings(string s) {
        memo = vector<int>(s.size(), -1);
        return foo(0, s);
    }
};