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
        // 只有当out为空的时候，再从in里导入数据（导入in全部数据）
        if (out.empty()) { 
             // 从in导入数据直到in为空
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

————————————————
版权声明：本文为CSDN博主「yolo0616」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_54447296/article/details/133356827
