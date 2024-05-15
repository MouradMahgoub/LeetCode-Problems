class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, cnt = 0;
        for(int num : nums)
            if(cnt == 0){
                ans = num;
                cnt = 1;
            }else{
                num == ans ? cnt++ : cnt--;
            }
        return ans;
    }
};
        // unordered_map<int, int> mp;
        // for(int i : nums) mp[i]++;
        // int ans=nums[0];
        // for(auto i : mp)
        //     if(i.second > mp[ans]) ans = i.first;
        // return ans;