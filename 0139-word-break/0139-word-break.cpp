class Solution {
public:
    string s;
    vector<string> wordDict;
    vector<int> memo;
    bool dp(int i) {
        if(i < 0) return true;
        if(memo[i] != -1) return memo[i];
        for(string word : wordDict){
            int n = word.size();
            if(i-n+1 < 0) continue;
            if(s.substr(i-n+1, n) == word && dp(i - n))
                return memo[i] = 1;
        }
        return memo[i] = 0;   
    } 
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s; this->wordDict = wordDict;
        this->memo = vector<int>(s.size(), -1);
        return dp(s.size()-1);
    }
};
        // if(curr == s) return true;
        // if(curr.size() > s.size() || curr != s.substr(0, curr.size())) return false;
        // bool f = false;
        // for(string val : wordDict){
        //         f |= foo(curr+val);
        //         if(f) return true;
        // }
        // return f;