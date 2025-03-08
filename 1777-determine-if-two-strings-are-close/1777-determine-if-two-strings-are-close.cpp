class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        unordered_map<char, int> mp1, mp2;
        vector<int> v1, v2;
        string temp1 = "", temp2 = "";
        for(char c : s1){
            if(mp1[c] == 0) temp1 += c;
            mp1[c]++;
        }
        for(char c : s2){
            if(mp2[c] == 0) temp2 += c;
            mp2[c]++;
        }
        if(mp1.size() != mp2.size()) return false;

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if(temp1 != temp2) return false;

        for(auto [c, cnt] : mp1) v1.push_back(cnt);
        for(auto [c, cnt] : mp2) v2.push_back(cnt);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i=0; i<v1.size(); i++)
            if(v1[i] != v2[i]) return false;
        return true;
    }
};