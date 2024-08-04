class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        min_st.push(min_st.empty() ? val : min(val, min_st.top()));
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */