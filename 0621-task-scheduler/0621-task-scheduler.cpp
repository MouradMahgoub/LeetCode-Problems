class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char c : tasks) mp[c]++;
        priority_queue<int> pq;
        for(auto [c, rep] : mp)
            pq.push(rep);
        queue<pair<int, int>> q;
        int currTime = 0;
        while(!pq.empty() || !q.empty()){
            currTime++;
            if(!pq.empty()){
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt != 0)
                    q.push({cnt, currTime+n});
            }
            if(!q.empty() && q.front().second <= currTime){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return currTime;
    }
};