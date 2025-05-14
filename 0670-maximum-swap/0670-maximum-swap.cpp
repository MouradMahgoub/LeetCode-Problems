class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<pair<int, char>> maxR(s.size(), {-1, '0'});
        maxR[s.size()-1] = {s.size()-1, s[s.size()-1]};
        for(int i=s.size()-2; i>=0; i--){
            maxR[i] = maxR[i+1];
            if(s[i] > maxR[i].second) maxR[i] = {i, s[i]};
        }
        for(int i=0; i<s.size()-1; i++)
            if(s[i] < maxR[i+1].second){
                swap(s[i], s[maxR[i+1].first]);
                break;
            }
        return stoi(s);
    }
};