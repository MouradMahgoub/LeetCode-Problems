class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int less = 0, grt = 0, eq=0;
        for(int num : nums) 
            if(num < pivot) less++;
            else if(num > pivot) grt++;
            else eq++;
        int i=0, k=less, j=less+eq;
        for(int num : nums)
            if(num < pivot) ans[i++] = num;
            else if(num > pivot) ans[j++] = num;
            else ans[k++] = num;
        return ans;
    }
};