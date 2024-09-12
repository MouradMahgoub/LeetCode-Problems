class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        bool flag;
        for(int i=0; i<words.size(); i++){
            flag = true;
            for(int j=0; j<words[i].length(); j++){
                if(allowed.find(words[i][j]) == string::npos) 
                    flag = false;
            }
                if(flag) count++;
        }  
        return count;
    }
};