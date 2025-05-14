class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i=0; i<s.size(); i++){
            int maxR = -1e9, indx = -1;
            for(int j=i+1; j<s.size(); j++){
                // maxR = max(maxR, s[j]-'0');
                if(s[j]-'0' >= maxR){
                    maxR = s[j]-'0';
                    indx = j;
                }
            }
            if(maxR > s[i]-'0'){
                swap(s[i], s[indx]);
                break;
            }
        }
        return stoi(s);
    }
};