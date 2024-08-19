class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tempList;

    bool is_palindrome (string s) {
        for(int i=0; i<s.size()/2; i++)
            if(s[i] != s[s.size()-1-i]) return false;
        return true;
    }

    void dfs (int start, string s) {
        if(start == s.size()){
            ans.push_back(tempList);
            return;
        }
        for(int i=start; i<s.size(); i++){
            string temps = s.substr(start, i-start+1); 
            if(is_palindrome(temps)){
                tempList.push_back(temps);
                dfs(i+1, s);
                tempList.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
};