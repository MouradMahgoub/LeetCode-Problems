class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        unordered_map<char, int> mp1, mp2;
        for(int i=0; i<s1.size(); i++) {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
            if(s1[i] != s2[i]) cnt++;
            if(cnt > 2) return false;
        }
        for(char c : s1) if(mp1[c] != mp2[c]) return false;
        return true;
    }
};