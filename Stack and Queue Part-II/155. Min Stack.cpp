class MinStack {
public:
    deque<int>q;
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(val<=q.front())
                q.push_front(val);
        else
            q.push_back(val);
    }
    
    void pop() {
        if(st.top()==q.front()){
            q.pop_front();
        }
        st.pop();
    }
    
    int top() {
        if(st.size()==0)
            return -1;
        return st.top();
    }
    
    int getMin() {
        return q.front();
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
