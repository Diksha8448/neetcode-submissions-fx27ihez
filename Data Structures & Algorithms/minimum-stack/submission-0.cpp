class MinStack {
public:
    stack<int>st;
    stack<int>minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        // we will push into minStack only if it is lesser
        if(minst.empty()||val<=minst.top()){
            minst.push(val);
        }
        
    }
    
    void pop() {
        if(st.top()==minst.top()){
            minst.pop();
        }
        st.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();
        
    }
};
