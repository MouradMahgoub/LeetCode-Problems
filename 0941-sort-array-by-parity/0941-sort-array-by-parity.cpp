class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int l=0, r=0; r<nums.size(); r++)
            if(nums[r]%2 == 0) swap(nums[l++], nums[r]);
        return nums;
    }
};
        // int n = nums.size(), l=0, r=n-1;
        // while(l < r){
        //     while(l < n && !(nums[l]&1)) l++;
        //     while(r >= 0 && nums[r]&1) r--;
        //     if(l < r) swap(nums[l], nums[r]);
        // }