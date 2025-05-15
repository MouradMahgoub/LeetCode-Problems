class Solution {
public:
    vector<string> ans;
    vector<string> split(string s, char c){
        vector<string> v;
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '.'){
                v.push_back(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }
        v.push_back(temp);
        return v;
    }

    bool check(string s){
        vector<string> v = split(s, '.');
        if(v.size() != 4) return false;
        for(string ss : v)
            if(ss == "" || stoll(ss) > 255 || ss != to_string(stoll(ss))) return false;
        return true;
    }
    void foo(string &s, int indx, int numdots, string currStr){
        if(numdots == 4 || indx == s.size()-1){
            currStr += s.substr(indx, s.size()-indx);
            if(check(currStr)) ans.push_back(currStr);
            return;
        }
        foo(s, indx+1, numdots, currStr + s[indx]);
        foo(s, indx+1, numdots+1, currStr + s[indx] + '.');
    }

    vector<string> restoreIpAddresses(string s) {
        foo(s, 0, 0, "");
        return ans;
    }
};