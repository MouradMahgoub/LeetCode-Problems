class Solution {
public:
    vector<vector<string>> ans;
    vector<string> part;
    bool is_palindrome (string s) {
        int l=0, r = s.size()-1;
        while(l < r) if(s[l++] != s[r--]) return false;
        return true;
    }
    void foo (int start, string s) {
        if(start == s.size()){
            ans.push_back(part);
            return;
        } 
        string temp = "";
        for(int i=start; i<s.size(); i++){
            temp += s[i];
            if(is_palindrome(temp)){
                part.push_back(temp);
                foo(i+1, s);
                part.pop_back();
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        foo(0, s);
        return ans;
    }
};