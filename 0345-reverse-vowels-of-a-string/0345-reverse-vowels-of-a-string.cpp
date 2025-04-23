class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> mp;
        mp['a']++;
        mp['i']++;
        mp['e']++;
        mp['o']++;
        mp['u']++;
        mp['A']++;
        mp['I']++;
        mp['E']++;
        mp['O']++;
        mp['U']++;
        vector<char> v;
        for(char c : s) if(mp[c]) v.push_back(c);
        int index = v.size() - 1;
        for(int i=0; i<s.size(); i++)
            if(mp[s[i]]) s[i] = v[index--];
        return s;
    }
};