class Solution {
public:
    bool check (vector<int>& nums, int k, int ans) {
        int cnt = 0, l = 0;
        for(int r=1; r<nums.size(); r++){
            while(nums[r]-nums[l] > ans) l++;
            cnt += (r-l);
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, r=1e6;
        while(l < r){
            int mid = l + (r-l)/2;
            if(check(nums, k, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
        // int n = *max_element(nums.begin(), nums.end()) + 5;
        // vector<int> mp (n, 0);
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         mp[abs(nums[j] - nums[i])]++;
        //     }
        // }
        // int ans=0;
        // for(int i=0; i<n; i++){
        //     ans = i;
        //     k -= mp[i];
        //     if(k <= 0) return ans;
        // }
        // return -1;