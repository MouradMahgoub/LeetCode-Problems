class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i] < 0) nums[i] = 0;
        for(int i=0; i<nums.size(); i++) {
            int indx = abs(nums[i]) - 1;
            if(indx >= 0 && indx < nums.size())
                if(nums[indx] == 0) nums[indx] = -(nums.size()+1);
                else if(nums[indx] > 0) nums[indx] *= -1;
        }
        for(int i=1; i<=nums.size(); i++)
            if(nums[i-1] >= 0) return i;
        return nums.size()+1;
    }
};
        // unordered_map<int, int> mp;
        // for(int num : nums) mp[num]++;
        // for(int i=1; i<=nums.size()+1; i++)
        //     if(mp[i] == 0)
        //         return i;
        // return -1;

        // sort(nums.begin(), nums.end());
        // int ans=1;
        // for(int num : nums){
        //     if(num > ans) break;
        //     if(num == ans) ans++;
        // }
        // return ans;