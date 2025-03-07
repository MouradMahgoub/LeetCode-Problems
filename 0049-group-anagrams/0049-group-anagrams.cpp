class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            //found
            if(mp.find(s) != mp.end()){
                mp[s].push_back(strs[i]);
            //NOt found
            }else{
                mp[s] = {strs[i]};
            }
        }
        vector<vector<string>> ans;
        for(auto [s, v] : mp) ans.push_back(v);
        return ans;
    }
};