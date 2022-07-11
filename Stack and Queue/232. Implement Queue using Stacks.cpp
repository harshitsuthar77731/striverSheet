class MyQueue {
public:
    stack<int>st1,st2;
    int tp = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.size()==0){
            tp = x;
        }
        st1.push(x);
    }
    
    int pop() {
        if(st1.size()==0)
            return -1;
        while(st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        if(st2.size()>0)
            tp = st2.top();
        int temp = st1.top();
        st1.pop();
        while(st2.size()>0)
        {    st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }
    
    int peek() {
        if(st1.size()==0)
            return -1;
        return tp;
    }
    
    bool empty() {
        if(st1.size()==0)
            return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
