class MinStack {
private:
    stack<int>st;
    stack<int>minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = val;
        if(!st.empty())
        {
            minVal = std::min(minVal, minStack.top());
        }
        minStack.push(minVal);
        st.push(val);
        
    }
    
    void pop() {
        st.pop();
        minStack.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
};
