class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int pb=0, pf=0, sum=0, ans=INT_MAX;
        while(pf < nums.size()){
            sum += nums[pf++];
            while(sum >= target){
                ans = min(ans, pf-pb);
                sum -= nums[pb++];
            } 
        }
        return ans == INT_MAX ? 0 : ans;
    }
};