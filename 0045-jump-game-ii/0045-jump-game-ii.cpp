class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currEnd=0, farthest=0, ans=0;
        for(int currIndx=0; currIndx<n-1; currIndx++){
            farthest = max(farthest, currIndx + nums[currIndx]);
            if(currIndx == currEnd){
                currEnd = farthest;
                ans++;
            }
        }
        return ans;
    }
};
        // int l=0, r=0, ans=0;
        // while(r < n-1){
        //     int widthOfWindow = 0;
        //     for(int i=l; i<=r; i++)
        //         widthOfWindow = max(widthOfWindow, i+nums[i]-r);
        //     ans++;
        //     l = r+1;
        //     r += widthOfWindow;
        // }
        // return ans;
        // vector<int> dp(n, 1e9);
        // dp[0] = 0;
        // for(int i=0; i<n; i++)
        //     for(int j=i+1; j<=i+nums[i] && j<n; j++)
        //         dp[j] = min(dp[j], dp[i]+1);
        // return dp[n-1];