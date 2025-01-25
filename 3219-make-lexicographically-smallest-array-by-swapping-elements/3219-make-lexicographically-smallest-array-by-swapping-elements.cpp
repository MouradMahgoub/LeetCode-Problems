class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // unordered_map<int, int> indx;
        // for(int i=0; i<nums.size(); i++) indx[nums[i]] = i;
        vector<pair<int, int>> v(nums.size());
        for(int i=0; i<v.size(); i++) v[i] = {nums[i], i};
        sort(v.begin(), v.end());
        priority_queue<int> numQ, indxQ; 
        vector<int> ans(v.size());
        numQ.push(-v[0].first);
        indxQ.push(-v[0].second);
        for(int i=1; i<v.size(); i++){
            if(v[i].first - v[i-1].first > limit) {
                while(!numQ.empty()){
                    ans[-indxQ.top()] = -numQ.top();
                    indxQ.pop();
                    numQ.pop();
                }
            }
            numQ.push(-v[i].first);
            indxQ.push(-v[i].second);
        }
        while(!numQ.empty()){
            ans[-indxQ.top()] = -numQ.top();
            indxQ.pop();
            numQ.pop();
        }
        return ans;
    }
};