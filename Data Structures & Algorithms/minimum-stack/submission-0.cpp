class MinStack {
    private:
    vector<int> custom_stack;
    public:
    MinStack() {
        
    }
    
    void push(int val) {
        custom_stack.push_back(val);
    }
    
    void pop() {
        custom_stack.pop_back();
        
    }
    
    int top() {
        return custom_stack[custom_stack.size()-1];
    }
    
    int getMin() {
        auto it = min_element(custom_stack.begin(), custom_stack.end());
        return *it;
        
    }
};
