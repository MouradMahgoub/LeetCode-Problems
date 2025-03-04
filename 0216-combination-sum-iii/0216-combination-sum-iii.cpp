class Solution {
public:
    vector<vector<int>> ans;
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> temp;

    void dfs(int curr, int sum, int k, int n){
        if(temp.size() == k){
            if(sum == n) ans.push_back(temp);
            return;
        }
        for(int i=curr; i<=9; i++){
            temp.push_back(i);
            dfs(i+1, sum+i, k, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 0, k, n);
        return ans;
    }





    // void dfs (int i, int len, int sum, int k, int target) {
    //     if(sum == target && len == k) ans.push_back(temp);
    //     if(i > 8 || len > k || sum >= target) return;

    //     temp.push_back(arr[i]);
    //     dfs(i+1, len+1, sum+arr[i], k, target);
    //     temp.pop_back();
        
    //     dfs(i+1, len, sum, k, target);
    // }
    //     dfs(0, 0, 0, k, n);
};