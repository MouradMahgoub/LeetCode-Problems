class Solution {
public:
    unordered_map<string, int> mp;
    vector<int> memo;

    int foo(int i, string str) {
        if(i > str.size()-1) return 0;
        if(memo[i] != -1) return memo[i];
        int res = str.size() - i + 1;
        res = 1 + foo(i+1, str);
        for(int j=i; j<str.size(); j++){
            if(mp.find(str.substr(i, j-i+1)) != mp.end())
                res= min(res, foo(j+1, str));
        }
        return memo[i] = res;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        memo = vector<int>(s.size(), -1);
        for(string s : dictionary) mp[s]++;
        return foo(0, s);
    }
};