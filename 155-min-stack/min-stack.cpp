class MinStack {
public:
    stack<pair<int,int>> st; //the first is the actual element, second is the minimum
    
    void push(int val) {
        if(st.size() > 0) st.push({val, min(val, st.top().second)});
        else st.push({val, val});
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