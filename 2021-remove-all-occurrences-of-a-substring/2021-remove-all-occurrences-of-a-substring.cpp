class Solution {
public:
     string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos)
            s.erase(s.find(part), part.size());
        return s;
    }

};
    // bool check(stack<char> &stk, string &part){
    //     stack<char> temp = stk;
    //     for(int i=part.size()-1; i>=0; i--) {
    //         if(temp.top() != part[i])
    //             return false;
    //         temp.pop();
    //     }
    //     return true;
    // }

    // string removeOccurrences(string s, string part) {
    //     stack<char> stk;
    //     int sLen = s.size(), pLen = part.size();
    //     for(int i=0; i<sLen; i++){
    //         stk.push(s[i]);
    //         if(stk.size() >= pLen && check(stk, part)){
    //             for(int j=0; j<pLen; j++) stk.pop();
    //         }
    //     }
    //     string ans = "";
    //     while(!stk.empty()){
    //         ans = stk.top() + ans;
    //         stk.pop();
    //     }
    //     return ans;
    // }