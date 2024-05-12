class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        for(int i=s.size()-1; ~i; i--)
            for(string word : wordDict)
                if(i+word.size()-1 < s.size() && s.substr(i, word.size()) == word && dp[i+word.size()])
                    dp[i] = true;
        return dp[0];
    }
};
        // this->s = s; this->wordDict = wordDict;
        // this->memo = vector<int>(s.size(), -1);
        // return dp(s.size()-1);
    // string s;
    // vector<string> wordDict;
    // vector<int> memo;
    // bool dp(int i) {
    //     if(i < 0) return true;
    //     if(memo[i] != -1) return memo[i];
    //     for(string word : wordDict){
    //         int n = word.size();
    //         if(i-n+1 < 0) continue;
    //         if(s.substr(i-n+1, n) == word && dp(i - n))
    //             return memo[i] = 1;
    //     }
    //     return memo[i] = 0;   
    // } 