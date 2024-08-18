class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        st.insert(1);
        long curr;
        for(int i=0; i<n; i++){
            curr = *st.begin();
            st.erase(st.begin());
            st.insert(curr * 2);
            st.insert(curr * 3);
            st.insert(curr * 5);
        }
        return (int)curr;
    }
};