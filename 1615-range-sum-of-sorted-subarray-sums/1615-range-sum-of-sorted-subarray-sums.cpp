class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int> subArr;
        for(int i=0; i<n; i++){
            int sub = 0;
            for(int j=i; j<n; j++){
                sub += nums[j];
                subArr.push(-sub);
            }
        }
        int temp = left-1;
        while(temp--) subArr.pop();
        temp = right-left+1;
        int ans = 0;
        while(temp--){
            ans = (ans + -subArr.top())%(1000000007);
            subArr.pop();
        } 
        return ans;
    }
};