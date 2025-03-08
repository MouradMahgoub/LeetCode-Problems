class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        vector<int> v1(26, 0), v2(26, 0);
        string temp1 = "", temp2 = "";
        for(char c : s1){
            if(v1[c - 'a'] == 0) temp1 += c;
            v1[c - 'a']++;
        }
        for(char c : s2){
            if(v2[c - 'a'] == 0) temp2 += c;
            v2[c - 'a']++;
        }
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return temp1 == temp2 && v1 == v2;  
    }
};