class MinStack {
public:
    stack<long long> st; // stores (value - mini)
    long long mini;

    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        if(st.empty()) {
            st.push(0);
            mini = value;
        }
        else {
            long long diff = value - mini;
            st.push(diff);
            if(diff <= 0) mini = value; 
            else mini = mini;
        }
    }
    
    void pop() {
        if(st.top() <= 0) { // it means, mini was st.top(), so now we need to update the mini to old minimum.
            mini = mini - st.top(); // coz, top = value - mini, and mini = value
        }

        st.pop();
    }
    
    int top() {
        if(st.top() <= 0) return mini;
        return st.top() + mini;
    }
    
    int getMin() {
        return mini;
    }
};
