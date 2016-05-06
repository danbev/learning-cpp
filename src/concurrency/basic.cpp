#include <iostream>
#include <thread>

void hello() {
    std::cout << "Helo" << std::endl;
}

class Task {
    public:
        Task(const char* name) {
            std::cout << "Creating Task " << name << std::endl;
            this->name_ = name;
        }
        Task(const Task& task) {
            std::cout << "Copying Task " << task.name_ << std::endl;
            this->name_ = task.name_;
        }
        ~Task() {
            std::cout << "Destroying Task " << name_ << std::endl;
        }
        void hello() const {
            std::cout << name_ << " helo" << std::endl;
        }
        void operator()() const {
            hello();
        }
    private:
        const char* name_;
};

int main(int argc, char **argv) {
    std::thread t1 {hello};
    t1.join();

    // This will first create an instance of type Task using the constructor Task(const char* name)
    // Then it will create an instance of type Task using the constructor Task(const Task& task)
    // Then it will create an instance of type Task using the constructor Task(const Task& task) which
    // will be passed to the new thread.
    // It will destroy the instance created using the constructor.
    // It will destroy the instance created using the copy constructor (not the one passed to the thread).
    std::thread t2 (Task("task 1"));
    t2.join();
    return 0;
}
