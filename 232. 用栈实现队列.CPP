class MyQueue {
public:
stack<int> in;
stack<int> out; 
    MyQueue() {
       
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int result = out.top();
        out.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }
    
    bool empty() {
         return in.empty() && out.empty();
    }
};
