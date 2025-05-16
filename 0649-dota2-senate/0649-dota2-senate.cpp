class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;
        for(int i=0; i<senate.size(); i++)
            if(senate[i] == 'R') rq.push(i);
            else dq.push(i);
        while(!rq.empty() && !dq.empty()){
            if(rq.front() < dq.front()){
                rq.push(rq.front() + senate.size());
            }else{
                dq.push(dq.front() + senate.size());
            }
            dq.pop();
            rq.pop();
        }   
        return rq.empty() ? "Dire" : "Radiant";     
    }   
};