class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        int i = 0, j = 0, index = 0;
        string ans(n+m, ' ');
        while(i < n || j < m){
            if(i < n){
                ans[index++] = w1[i++];
            }
            if(j < m){
                ans[index++] = w2[j++];
            }
        }
        return ans;
    }
};