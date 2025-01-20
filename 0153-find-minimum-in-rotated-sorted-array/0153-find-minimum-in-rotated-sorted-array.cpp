class Solution {
public:
    int findMin(vector<int>& nums) {
        // int l=0, r=nums.size()-1;
        // while(l < r){
        //     int mid = l + (r-l+1)/2;
        //     if(nums[mid] >= nums[l]) l = mid;
        //     else r = mid-1;
        // }
        // return nums[l];
        return foo(nums, 0, nums.size()-1);
    }
    int foo(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        int mid = (l+r)/2;
        if(nums[mid] <= nums[r])
            return foo(nums, l, mid);
        return foo(nums, mid+1, r);
    }


};