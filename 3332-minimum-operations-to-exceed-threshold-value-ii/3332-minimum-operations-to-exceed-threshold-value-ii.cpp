class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long> pq;
        int cnt = 0;
        for(int num : nums) pq.push(-num);
        while(-pq.top() < k){
            cnt++;
            long x = -pq.top(); pq.pop();
            long y = -pq.top(); pq.pop();
            pq.push(-(x*2 + y));
        }
        return cnt;
    }
};