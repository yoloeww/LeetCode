#include<iostream>
#include<queue>
#include<mutex>
#incldue<thread>
class ReadWriteBuffer {  
public:  
    ReadWriteBuffer(size_t capacity) : buffer_(capacity) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (buffer_.size() == capacity) {
            cv_wait(lock);
        }
        buffer_.push(data,size);
        cv_notify_one();
    }
    void Write(const char* data,size_t size) {

    }
    void Read(char *data,size_t size) {
        std::unique_lock<std::mutex> lock(mutex_);
        while(buffer_.empty()) {
            cv_.wait(lock);
        }
        size_t read_size = std::min(size,buffer_.front().size());
        buffer_.pop_front(data,read_size);
        cv_notify_one();
    }
private:
    std::queue<string::string> buffer_;
    std:mutux mutex_;
    std::condition_variable cv_;
};
