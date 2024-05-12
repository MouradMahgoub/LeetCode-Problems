class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;
    vector<string> foo(string curr) {
        if(!memo.count(curr))
            for(int i=1; i<=curr.size(); i++)
                if(dict.count(curr.substr(0, i)))
                    for(string res : foo(curr.substr(i)))
                        memo[curr].push_back(curr.substr(0, i) + (res == "" ? "" : " ") + res);
        return memo[curr];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string> (wordDict.begin(), wordDict.end());
        memo[""].push_back("");
        return foo(s);
    }
}; 