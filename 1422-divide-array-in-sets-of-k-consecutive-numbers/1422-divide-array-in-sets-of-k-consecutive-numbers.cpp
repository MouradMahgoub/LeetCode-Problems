class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k) return false;
        map<int, int> mp;
        for(int& num : nums) mp[num]++;
        for(int i=0; i<(int)nums.size()/k; i++){
            int curr = mp.begin()->first;
            if(!(--mp[curr])) mp.erase(curr);
            for(int j=0; j<k-1; j++){
                if(!mp[++curr]) return false;
                if(!(--mp[curr])) mp.erase(curr);
            }
        }
        return true;
    }
};