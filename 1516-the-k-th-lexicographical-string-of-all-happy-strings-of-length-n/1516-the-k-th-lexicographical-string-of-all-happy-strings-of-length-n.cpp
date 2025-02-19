class Solution {
public:
    void dfs (int n, string currStr, vector<string>& strVec) {
        if(n == currStr.size()) {
            strVec.push_back(currStr);
            return;
        }
        for(char c = 'a'; c <= 'c'; c++){
            if(currStr.size() && currStr.back() == c) continue;
            dfs(n, currStr + c, strVec);
        }
    }

    string getHappyString(int n, int k) {
        vector<string> strVec;
        dfs(n, "", strVec);
        return k <= strVec.size() ? strVec[k-1] : "";
    }
};