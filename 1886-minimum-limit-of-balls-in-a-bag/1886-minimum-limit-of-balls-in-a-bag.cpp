class Solution {
public:
    bool good (vector<int>& nums, int maxOperations, int ans) {
        int sum=0;
        for(int& num : nums) sum += ceil(1.0*num/ans) - 1;
        return sum <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int mid = l + (r-l)/2;
            if(good(nums, maxOperations, mid)) r = mid;
            else l = mid + 1; 
        }
        return l;
    }
};