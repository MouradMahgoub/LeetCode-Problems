class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=0, i=0;
        while(i < nums.size()){
            int curr=nums[i], cnt=0;
            while(i < nums.size() && curr == nums[i]){
                cnt++; i++;
                if(cnt > 2) continue;
                nums[p++] = curr;
            }
        }
        return p;
    }
};