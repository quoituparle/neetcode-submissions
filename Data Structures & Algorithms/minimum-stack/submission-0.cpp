class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mst.push(val);
        } else {
            if (val <= mst.top()) mst.push(val);
            st.push(val);
        }
    }
    
    void pop() {
        if (st.top() == mst.top()) {
            mst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
private:
    stack<int> st;
    stack<int> mst;
};
