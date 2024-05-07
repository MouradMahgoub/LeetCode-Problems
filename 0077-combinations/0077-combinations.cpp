class Solution {
public:
    vector<vector<int>> ans;

    void foo(int start, vector<int> comb , int n, int k){
        comb.push_back(start);
        if(comb.size() == k){
            ans.push_back(comb);
        }else{
            for(int i=start+1; i<=n; i++){
                foo(i, comb, n, k);
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        for(int i=1; i<=n; i++)
            foo(i, vector<int>(), n, k);
        return ans;
    }
};