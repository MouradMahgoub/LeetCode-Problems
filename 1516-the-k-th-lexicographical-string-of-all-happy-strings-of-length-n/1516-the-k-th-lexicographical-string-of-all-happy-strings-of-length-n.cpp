class Solution {
public:
    string ans = "";
    int cnt = 0;
    void dfs (int n, int k, string currStr) {
        if(n == currStr.size()) {
            cnt++;
            if(cnt == k) ans = currStr;
            return;
        }
        for(char c = 'a'; c <= 'c'; c++){
            if(currStr.size() && currStr.back() == c) continue;
            dfs(n, k, currStr + c);
            if(ans != "") return;
        }
    }

    string getHappyString(int n, int k) {
        dfs(n, k, "");
        return ans;
    }
};