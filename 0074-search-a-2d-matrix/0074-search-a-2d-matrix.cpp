class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=int(matrix.size());
        while(l < r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0] <= target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(l == 0) return false;
        int row = l - 1;
        l=0, r=int(matrix[0].size())-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(matrix[row][mid] == target){
                return true;
            }else if(matrix[row][mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};