class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ']'){
                st.push(string(1, s[i]));
            }else{
                string str = "";
                while(!st.empty() && st.top() != "[") {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();    // pop '['

                string num = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }
                int k = stoi(num);
                cout << k << "\n";

                string temp = "";
                while(k--) temp += str;
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

        // stack<int> stNum;
        // stack<string> stStr;
        // stNum.push(1);
        // stStr.push("");
        // int i = 0;
        // while(i < s.size()) {
        //     if(isdigit(s[i])){
        //         int  k = 0;
        //         while(isdigit(s[i])){
        //             k = k*10 + (s[i] - '0');
        //             i++;
        //         }
        //         stNum.push(k);
        //         stStr.push("");
        //         i++; // skip '['
        //     }
        //     if(isalpha(s[i])) {
        //         string temp = stStr.top(); stStr.pop();
        //         while(isalpha(s[i])) {
        //             temp += s[i];
        //             i++;
        //         }
        //         stStr.push(temp);
        //     }
        //     if(s[i] == ']') {
        //         int k = stNum.top(); stNum.pop();
        //         string temp = "";
        //         while(k--) temp += stStr.top();
        //         stStr.pop();
        //         string prfxStr = stStr.top(); stStr.pop();
        //         stStr.push(prfxStr + temp);
        //         i++;
        //     }
        // }
        // return stStr.top();