class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> exist;
        int ans=0;
        for(int r=0, l=0; r<s.size(); r++){
            while(exist.count(s[r])){
                exist.erase(s[l]);
                l++;
            }
            exist.insert(s[r]);
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};