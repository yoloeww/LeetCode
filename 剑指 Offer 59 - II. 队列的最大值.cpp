class MaxQueue {
queue<int> que;
deque<int> deq;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return deq.empty() ? -1 : deq.front();
     }
    
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && deq.back() < value) {
            deq.pop_back();
        }
        deq.push_back(value);
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int val = que.front();
        if (val == deq.front())
            deq.pop_front();
        que.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
