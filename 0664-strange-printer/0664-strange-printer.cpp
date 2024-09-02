class Solution {
public:
    int memo[105][105];

    int foo (int start, int end, string s) {
         if (start > end) return 0;
        if(memo[start][end] != -1) return memo[start][end];
        int ans = 1 + foo(start+1, end, s);
        for(int k=start+1; k<=end; k++){
            if(s[start] == s[k])
                ans = min(ans, foo(start+1, k-1, s) + foo(k, end, s));
        }
        return memo[start][end] = ans; 
    }

    int strangePrinter(string s) {
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            temp += s[i];
            while(i < s.size()-1 && s[i] == s[i+1]) i++;
        }
        s = temp;
        memset(memo, -1, sizeof(memo));
        return foo(0, s.size()-1, s);
    }
};