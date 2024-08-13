class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l=0, r=n-1;
        int t=0, d=n-1;
        vector<vector<int>> arr(n, vector<int>(n));
        int cnt = 1;
        while(l <= r && t <= d){
            //top row
            for(int i=l; i<=r; i++) arr[t][i] = cnt++;
            t++;
            //right col
            for(int i=t; i<=d; i++) arr[i][r] = cnt++;
            r--;
            //down row
            for(int i=r; i>=l;i--) arr[d][i] = cnt++;
            d--;
            //left col
            for(int i=d; i>=t; i--) arr[i][l] = cnt++;
            l++;
        }
        return arr;
    }
};