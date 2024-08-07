class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size(), m=arr[0].size();
        int l=0, r=n-1;
        int row = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid][0] <= target) {
                row = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(row == -1) return false;
        int col = -1;
        l=0, r=m-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[row][mid] == target) return true;
            else if(arr[row][mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};