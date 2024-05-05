class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people), greater<int>());
        deque<int> dq(begin(people), end(people));
        int ans=0;
        while(dq.size() > 1){
            if(dq.front() + dq.back() <= limit) dq.pop_back();
            dq.pop_front();
            ans++;
        }
        return ans + (int)dq.size();
    }
};