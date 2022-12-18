class MyStack {
public:
    queue <int> que;
    MyStack() {

    }
    
    void push(int x) {
    que.push(x);
    }
    
    int pop() {
    int size = que.size() - 1;
    while (size --) {
        que.push(que.front());
        que.pop();
    }
    int result = que.front();
    que.pop();
    return result;
    }
    
    int top() {
    return que.back();
    }
    
    bool empty() {
    return que.empty();
    }
};
