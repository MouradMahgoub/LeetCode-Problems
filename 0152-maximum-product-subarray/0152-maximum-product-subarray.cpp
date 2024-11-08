class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], maxi = 1, mini = 1;
        for(int num : nums){
            // if(num < 0) swap(mini, maxi);
            int temp = maxi;
            maxi = max(num, max(maxi*num, mini*num));
            mini = min(num, min(mini*num, temp*num));
            ans = max(ans, maxi);
        }
        return ans;
    }
};