class MinStack {
public:
    stack<pair<int, int>> st; // the first is the actual element, second is the minimum

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.size() > 0) st.push({value, min(value, st.top().second)});
        else st.push({value, value});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
