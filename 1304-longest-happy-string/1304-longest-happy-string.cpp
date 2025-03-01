class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});

        while(!pq.empty()){
            auto [cnt1, letter1] = pq.top(); pq.pop();
            if(s.size() > 1 && s[s.size()-1] == letter1 && s[s.size()-2] == letter1){
                if(pq.empty()) break;
                auto [cnt2, letter2] = pq.top(); pq.pop();
                s += letter2;
                cnt2--;
                if(cnt2 != 0) pq.push({cnt2, letter2});
            }else{
                s += letter1;
                cnt1--;
            }
            if(cnt1 != 0) pq.push({cnt1, letter1});
        }
        return s;
    }
};