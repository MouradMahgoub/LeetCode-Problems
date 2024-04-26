class Solution {
public:
    int longestIdealString(string s, int k) {
        unordered_map<char, int> mp;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            int mx = 1;
            for(char c='a'; c<='z'; c++){
                if(abs(s[i] - c) <= k)
                    mx = max(mx, 1+mp[c]);
            }
            mp[s[i]] = max(mp[s[i]], mx);
            ans = max(ans, mp[s[i]]);
        }
        return ans;
    }
};