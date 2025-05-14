class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>mp;
        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        for(auto [s, v] : mp)
            ans.push_back(v);
        return ans;
    }
};


        // unordered_map<string, vector<string>> mp;
        // for(int i=0; i<strs.size(); i++){
        //     string s = strs[i];
        //     sort(s.begin(), s.end());
        //     //found
        //     if(mp.find(s) != mp.end()){
        //         mp[s].push_back(strs[i]);
        //     //NOt found
        //     }else{
        //         mp[s] = {strs[i]};
        //     }
        // }
        // vector<vector<string>> ans;
        // for(auto [s, v] : mp) ans.push_back(v);
        // return ans;