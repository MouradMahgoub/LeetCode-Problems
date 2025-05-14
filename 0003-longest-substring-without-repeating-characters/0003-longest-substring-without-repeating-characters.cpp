class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, l = 0;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()) l = max(l, mp[s[i]]+1);
            mp[s[i]] = i;
            ans = max(ans, i-l+1);
        }
        return ans; 
    }
};




        // unordered_set<int> exist;
        // int ans=0;
        // for(int r=0, l=0; r<s.size(); r++){
        //     while(exist.count(s[r])) exist.erase(s[l++]);
        //     exist.insert(s[r]);
        //     ans = max(ans, r-l+1);
        // }
        // return ans;