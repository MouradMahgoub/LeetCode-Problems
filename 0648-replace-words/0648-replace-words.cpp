class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> mp;
        for(string s : dictionary) mp[s]++;
        string ans = "";
        for(int i=0; i<sentence.size(); i++){
            string curr = "";
            while(!mp[curr] && i < sentence.size() && sentence[i] != ' '){
                curr += sentence[i++];
            }
            ans += curr + " ";
            while(i < sentence.size() && sentence[i] != ' ') i++;
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};