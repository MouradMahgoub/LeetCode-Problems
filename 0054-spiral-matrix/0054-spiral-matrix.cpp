class Solution {
public:
    bool valid(int l, int r, int t, int d){
        return l <= r && t <= d;        
    }
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n=arr.size(), m=arr[0].size();
        int l=0, r=m-1;
        int t=0, d=n-1;
        vector<int> ans;
        while(valid(l, r, t, d)){
            //top row
            for(int i=l; i<=r; i++) ans.push_back(arr[t][i]);
            t++;
            if(!valid(l, r, t ,d)) break;
            //right col
            for(int i=t; i<=d; i++) ans.push_back(arr[i][r]);
            r--;
            if(!valid(l, r, t ,d)) break;
            //down row
            for(int i=r; i>=l;i--) ans.push_back(arr[d][i]);
            d--;
            if(!valid(l, r, t ,d)) break;
            //left col
            for(int i=d; i>=t; i--) ans.push_back(arr[i][l]);
            l++;
        }
        return ans;
    }
};