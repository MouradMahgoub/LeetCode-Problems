class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxi=0;
        int l=0, r=0;
        for(l=0, r=0; r<s.size(); r++){
            mp[s[r]]++;
            for(auto [c, rep] : mp) maxi = max(maxi, rep);
            if(r-l+1 - maxi > k){
                mp[s[l]]--;
                l++;
            }
        }
        return r-l;
    }
};