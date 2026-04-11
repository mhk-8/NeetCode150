class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } 
        else {
            int current_min = min(val, st.top().second);
            st.push({val, current_min});
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
