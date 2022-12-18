class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;
    MyQueue() {
     
    }
    void push(int x) {
    stackIn.push(x);
    }
    
    int pop() {
    if (stackOut.empty()) {
        while (!stackIn.empty()) {
            stackOut.push(stackIn.top());
            stackIn.pop();
        }
    }
    int result = stackOut.top(); 
    stackOut.pop();
    return result;
    }
    
    int peek() {
    int res = this->pop();
    stackOut.push(res);
    return res;
        }
    
    bool empty() {
    return stackIn.empty() && stackOut.empty();
    }
};
