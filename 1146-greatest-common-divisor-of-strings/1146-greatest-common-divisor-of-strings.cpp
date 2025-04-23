class Solution {
public:
    bool isDivisible (string s, string div) {
        if(s.size()%div.size() != 0) return false;
        for(int i=0; i<s.size(); i+=div.size())
            if(s.substr(i, div.size()) != div) return false;
        return true;
    }   
    string gcdOfStrings(string s1, string s2) {
        string currDiv = "", ans = "";
        for(int i=0; i<min(s1.size(), s2.size()); i++){
            if(s1[i] != s2[i]) break;
            currDiv += s1[i];
            if(isDivisible(s1, currDiv) && isDivisible(s2, currDiv)) ans = currDiv;
        }
        return ans;
    }
};