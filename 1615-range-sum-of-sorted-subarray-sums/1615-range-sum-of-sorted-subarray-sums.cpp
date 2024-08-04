class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++) pq.push({-nums[i], i});
        int ans=0, mod = 1e9 + 7;;
        for(int i=1; i<=right; i++){
            auto [val, indx] = pq.top(); pq.pop();
            if(i >= left) ans = (ans + -val)%mod;
            if(indx < n-1) pq.push({val-nums[indx+1], indx+1});
        }
        return ans;
    }
};
        // for(int i=0; i<n; i++){
        //     int sub = 0;
        //     for(int j=i; j<n; j++){
        //         sub += nums[j];
        //         subArr.push(-sub);
        //     }
        // }
        // int temp = left-1;
        // while(temp--) subArr.pop();
        // temp = right-left+1;
        // int ans = 0;
        // while(temp--){
        //     ans = (ans + -subArr.top())%(1000000007);
        //     subArr.pop();
        // } 