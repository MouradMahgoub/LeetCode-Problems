class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";
        path += '/';
        for(char c : path){
            if(c == '/'){
                if(curr == "..") {
                    if(!st.empty()) 
                        st.pop();
                }else if(curr != "." && curr != ""){
                    st.push(curr);
                }
                curr = "";
            }else curr += c;
        }
        
        string ans = "";
        while(!st.empty()){
            ans =  '/' + st.top() + ans;
            st.pop();
        }
        if(ans == "") ans = "/";
        return ans;
    }
};
        // string simpath = "/";
        // for(int i=1; i<n; i++){
        //     if(path[i] == '/' && path[i-1] == '/') continue;
        //     simpath += path[i];
        // }
        // n = simpath.size();
        // for(int i=1; i<n; i++){
        //     string temp = "";
        //     while(i < n && simpath[i] != '/'){
        //         temp += simpath[i++];
        //     }            
        //     if(temp == ".") continue;
        //     if(temp == "..") {
        //         if(!st.empty()) st.pop();
        //         continue;
        //     }
        //     st.push(temp);
        // }
        // string ans = "";
        // while(!st.empty()){
        //     ans = ("/" + st.top() + ans);
        //     st.pop();
        // } 
        // if(ans.size() == 0) ans = "/";