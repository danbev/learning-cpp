#include <iostream>
#include <thread>

void hello() {
    std::cout << "Helo" << std::endl;
}

class Task {
    public:
        void doit() const {
            std::cout << "Task doing it..." << std::endl;
        }
        void operator()() const {
            doit();
        }
};

int main(int argc, char **argv) {
    std::thread t1 {hello};
    t1.join();

    Task task;
    std::thread t2 {task};
    t2.join();
    return 0;
}
