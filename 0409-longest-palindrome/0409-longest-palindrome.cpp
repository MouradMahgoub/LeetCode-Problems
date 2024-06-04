class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        int ans = 0, odd = 0;
        for(auto [c, cnt] : mp){
            ans += cnt - cnt%2;
            odd = max(odd, cnt%2);
        }
        return ans+odd;
    }
};