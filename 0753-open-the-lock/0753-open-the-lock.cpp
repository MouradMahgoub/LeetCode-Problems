class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> mp1, mp2;
        mp1['0'] = '9';
        mp1['1'] = '0';
        mp1['2'] = '1';
        mp1['3'] = '2';
        mp1['4'] = '3';
        mp1['5'] = '4';
        mp1['6'] = '5';
        mp1['7'] = '6';
        mp1['8'] = '7';
        mp1['9'] = '8';
        mp2['0'] = '1';
        mp2['1'] = '2';
        mp2['2'] = '3';
        mp2['3'] = '4';
        mp2['4'] = '5';
        mp2['5'] = '6';
        mp2['6'] = '7';
        mp2['7'] = '8';
        mp2['8'] = '9';
        mp2['9'] = '0';
        unordered_set<string> deads;
        for(auto i : deadends)
            deads.insert(i);
        if(deads.count("0000")) return -1;
        // if(target == "0000") return 0;
        queue<string> q;
        q.push("0000");
        int ans=0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                string curr = q.front();
                q.pop();
                if(curr == target) return ans;
                for(int i=0; i<4; i++){
                    string temp = curr;
                    temp[i] = mp1[temp[i]];
                    if(!deads.count(temp)){
                        deads.insert(temp);
                        q.push(temp);
                    }
                    temp = curr;
                    temp[i] = mp2[temp[i]];
                    if(!deads.count(temp)){
                        deads.insert(temp);
                        q.push(temp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};