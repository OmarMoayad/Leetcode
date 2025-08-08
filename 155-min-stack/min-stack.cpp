class MinStack {
public:
    stack<int> st;
    
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int minVal = st.top();
        stack<int> temp = st;
        while (!temp.empty()) {
            minVal = min(minVal, temp.top());
            temp.pop();
        }
        return minVal;
    }
};