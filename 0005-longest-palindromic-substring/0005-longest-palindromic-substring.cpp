class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int ansLen = 0;
        for(int i=0; i<n; i++){
            //check odd
            int l=i, r=i;
            while(l >= 0 && r < n && s[l] == s[r]){
                ansLen = r-l+1;
                if(ansLen > ans.size())
                    ans = s.substr(l, ansLen);
                l--; r++;
            }
            //check even
            l=i, r=i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                ansLen = r-l+1;
                if(ansLen > ans.size())
                    ans = s.substr(l, ansLen);
                l--; r++;
            }
        }
        return ans;
    }
};
        // int n = s.size();
        // vector<vector<bool>> dp(n+5, vector<bool>(n+5));
        // pair<int, int> ans = {0, 0};
        // for(int i=0; i<n; i++) dp[i][i] = true;
        // for(int i=0; i<n-1; i++) 
        //     if(s[i] == s[i+1]){
        //         dp[i][i+1] = true;
        //         ans = {i, i+1};
        //     }
        // for(int i=2; i<n; i++)
        //     for(int j=0; j+i<n; j++)
        //         if(s[j] == s[j+i] && dp[j+1][j+i-1]){
        //             dp[j][j+i] = true;
        //             ans = {j, j+i};
        //         }
        // return s.substr(ans.first, (ans.second-ans.first+1));