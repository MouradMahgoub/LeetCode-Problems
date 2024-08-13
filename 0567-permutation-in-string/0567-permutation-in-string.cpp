class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp1, mp2;
        for(char c : s1) mp1[c]++;
        for(int i=0; i<s2.size(); i++){
            if(i < s1.size()-1) mp2[s2[i]]++;
            else {
                mp2[s2[i]]++;
                int flag = 1;
                for(char c='a'; c<='z'; c++){
                    if(mp1[c] != mp2[c]){
                        flag = 0;
                        break;
                    }
                }
                if(flag) return true;
                mp2[s2[i-s1.size()+1]]--;
            }
        }
        return false;
    }
};