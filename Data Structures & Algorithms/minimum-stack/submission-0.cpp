class MinStack {
private:
    vector<int> main;
    vector<int> min_atual;

public:
    MinStack() {}
    
    void push(int val) {
        main.push_back(val);
        if (min_atual.empty()) min_atual.push_back(val);
        else(min_atual.push_back(min(min_atual.back(),val)));
    }
    
    void pop() {
        main.pop_back();
        min_atual.pop_back();
    }
    
    int top() {
        return main.back();
    }
    
    int getMin() {
        return min_atual.back();
    }
};
