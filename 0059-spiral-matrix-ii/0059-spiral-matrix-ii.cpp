class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int curr=1;
        int l=0, r=n-1;
        int t=0, b=n-1;
        while(1){
            for(int i=l; i<=r; i++) ans[t][i] = curr++;
            t++;
            if(l > r || t > b) break;
            for(int i=t; i<=b; i++) ans[i][r] = curr++;
            r--;
            if(l > r || t > b) break;
            for(int i=r; i>=l; i--) ans[b][i] = curr++;
            b--;
            if(l > r || t > b) break;
            for(int i=b; i>=t; i--) ans[i][l] = curr++;
            l++;
            if(l > r || t > b) break;
        }
        return ans;
    }
};