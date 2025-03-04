class Solution {
public:
    vector<string> ans;
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string temp = "";

    void dfs(int i, string digits){
        if(i == digits.size()){
            if(!temp.empty()) ans.push_back(temp);
            return;
        }
        for(char c : mp[digits[i] - '0']){
            temp += c;
            dfs(i+1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        dfs(0, digits);
        return ans;
    }
};







        // dfs(0, digits);
    // void dfs (int i, string digits) {
    //     if(i == digits.size()){
    //         if(!temp.empty()) ans.push_back(temp);
    //         return;
    //     } 
    //     for(char c : map[digits[i] - '0']){
    //         temp.push_back(c);
    //         dfs(i+1, digits);
    //         temp.pop_back();
    //     }
    // }