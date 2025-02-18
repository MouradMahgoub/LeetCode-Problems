class Solution {
public:
    unordered_map<char, int> mp;
    int dfs () {
        int  cnt = 0;
        for(auto [c, n] : mp){
            if(n > 0) {
                mp[c]--;
                cnt += 1 + dfs();
                mp[c]++;
            }
        }
        return cnt;
    }
    int numTilePossibilities(string s) {
        for(char c : s) mp[c]++;
        return dfs();
    }
};