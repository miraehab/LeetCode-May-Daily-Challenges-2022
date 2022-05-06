class MyStack {
public:
    queue<int> nums;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = nums.size();
        nums.push(x);
        for(int i = 0; i < s; ++i){
            int tmp = nums.front();
            nums.pop();
            nums.push(tmp);
        }
    }
    
    int pop() {
        int tmp = nums.front();
        nums.pop();
        return tmp;
    }
    
    int top() {
        return nums.front();
    }
    
    bool empty() {
        return nums.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */