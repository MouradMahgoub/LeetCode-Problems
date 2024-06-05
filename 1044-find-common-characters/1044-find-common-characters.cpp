class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<map<char, int>> v(words.size());
        for(int i=0; i<words.size(); i++)
            for(char c : words[i]) v[i][c]++;
        vector<string> ans;
        for(char c : words[0]){
            bool f = true;
            for(int i=0; i<v.size(); i++)
                if(--v[i][c] < 0) f = false;
            if(f) ans.push_back(string(1, c)); 
        }
        return ans;
    }
};