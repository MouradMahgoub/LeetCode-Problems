class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0, r=matrix[0].size();
        int t=0, b=matrix.size();
        while(l <= r && t <= b){
            //top row
            for(int i=l; i<r; i++) ans.push_back(matrix[t][i]);
            t++;
            if(t >= b) break;
            //right col
            for(int i=t; i<b; i++) ans.push_back(matrix[i][r-1]);
            r--;
            if(r <= l) break;
            //bottom row
            for(int i=r-1; i>=l; i--) ans.push_back(matrix[b-1][i]);
            b--;
            if(b <= t) break;
            //left col
            for(int i=b-1; i>=t; i--) ans.push_back(matrix[i][l]);
            l++;
            if(l >= r) break;
        }
        return ans;   
    }
};