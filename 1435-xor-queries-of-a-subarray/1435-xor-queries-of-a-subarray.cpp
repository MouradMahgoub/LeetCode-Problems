class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prfx(arr.size()+1, 0);
        for(int i=0; i<arr.size(); i++)
            prfx[i+1] = prfx[i] ^ arr[i];
        vector<int> ans(queries.size());
        for(int i=0; i<ans.size(); i++){
            int l = queries[i][0], r = queries[i][1];
            ans[i] = prfx[r+1]^prfx[l];
        }
        return ans;
    }
};