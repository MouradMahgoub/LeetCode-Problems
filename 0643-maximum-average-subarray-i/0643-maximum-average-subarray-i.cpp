class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans = -1e18;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(i >= k-1){
                ans = max(ans, sum/k);
                sum -= nums[i-k+1];
            }
        }
        return ans;
    }
};