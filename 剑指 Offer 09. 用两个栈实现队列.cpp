class CQueue {
public:
    stack<int> in,out;
    CQueue() {
        // while (!in.empty()) {
        //     in.pop();
        // }
        // while (!out.empty()) {
        //     out.pop();
        // }
    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(out.empty()) { // in -> out
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty())
            return -1;
        else {
            int deletevalue = out.top();
            out.pop();
            return deletevalue;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
