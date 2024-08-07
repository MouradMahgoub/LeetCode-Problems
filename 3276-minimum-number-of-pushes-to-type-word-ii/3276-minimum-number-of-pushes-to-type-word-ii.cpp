class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(30, 0);
        for(char c : word) mp[c - 'a']++;
        sort(mp.rbegin(), mp.rend());
        for(int i : mp) cout << i << " ";
        int ans=0;
        for(int i=0; i<30; i++) ans += mp[i]*((i+8)/8);
        return ans;
    }
};