class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(char c : s1) mp1[c]++;
        for(int i=0; i<s2.size(); i++){
            if(i < s1.size()-1){
                mp2[s2[i]]++;
            }else{
                int flag = 1;
                mp2[s2[i]]++;
                for(char c : s1){
                    if(mp1[c] != mp2[c]){
                        flag = 0;
                        break;
                    }
                }
                if(flag) return true;
                mp2[s2[i - (s1.size()-1)]]--;
            }
        }
        return false;
    }
};