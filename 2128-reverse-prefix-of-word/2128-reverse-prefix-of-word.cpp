class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.size(); i++)
            if(word[i] == ch){
                string r = word.substr(0, i+1); 
                reverse(r.begin(), r.end());
                return r + word.substr(i+1, word.size()-i-1);    
            } 
        return word;
    }
};