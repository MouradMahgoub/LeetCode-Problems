class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        set<vector<int>> visited;
        auto comp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        pq.emplace(vector<int>{nums1[0]+nums2[0], 0, 0});
        while(ans.size() < k){
            vector<int> v = pq.top();
            pq.pop();
            int sum = v[0], i = v[1], j = v[2];
            ans.emplace_back(vector<int>{nums1[i], nums2[j]});
            if(i+1 < nums1.size() && !visited.count({i+1, j})){
                pq.emplace(vector<int>{nums1[i+1]+nums2[j], i+1, j});
                visited.insert({i+1, j});
            } 
            if(j+1 < nums2.size() && !visited.count({i, j+1})){
                pq.emplace(vector<int>{nums1[i]+nums2[j+1], i, j+1});
                visited.insert({i, j+1});
            } 
        }
        return ans;
    }
};