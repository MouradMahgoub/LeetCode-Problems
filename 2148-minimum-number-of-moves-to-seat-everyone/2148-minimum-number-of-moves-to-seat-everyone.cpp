class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        priority_queue<int> q1, q2;
        int ans=0;
        for(int i=0; i<seats.size(); i++){
            q1.push(seats[i]);
            q2.push(students[i]);
        }
        for(int i=0; i<seats.size(); i++){
            ans += abs(q1.top() - q2.top());
            q1.pop(); q2.pop();
        }
        return ans;
    }
};