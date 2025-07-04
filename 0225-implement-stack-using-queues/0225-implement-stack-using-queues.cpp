class MyStack {
public:
    queue<int> q;
    MyStack() {   
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
        int ans = q.front(); q.pop();
        return ans;
    }
    
    int top() {
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
        int ans = q.front(); q.pop();
        q.push(ans);
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */