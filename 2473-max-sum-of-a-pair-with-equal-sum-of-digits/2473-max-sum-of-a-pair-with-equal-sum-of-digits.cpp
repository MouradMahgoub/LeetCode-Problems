class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;
        for(int num : nums){
            int temp = num;
            int sum = 0;
            while(temp){
                sum += temp%10;
                temp /= 10;
            }
            mp[sum].push(num);
        }
        int ans = -1;
        for(auto [sum, pq] : mp)
            if(pq.size() > 1){
                int temp = pq.top(); pq.pop();
                temp += pq.top(); pq.pop();
                ans = max(ans, temp);
            }
        return ans;
    }
};