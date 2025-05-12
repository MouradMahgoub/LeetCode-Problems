class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp, rep;
        for(int d : digits) mp[d]++;
        vector<int> ans;
        
        for(int i=100; i<=999; i+=2){
            string s = to_string(i);
            rep[s[0] - '0']++;
            rep[s[1] - '0']++;
            rep[s[2] - '0']++;
            bool f = true;
            for(auto [c, n] : rep)
                if(n > mp[c]) f = false;
            if(f) ans.push_back(i);
            rep[s[0] - '0']--;
            rep[s[1] - '0']--;
            rep[s[2] - '0']--;
        }
        return ans;  
    }
};