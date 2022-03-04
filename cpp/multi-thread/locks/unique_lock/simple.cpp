#include <iostream>
#include <exception>
#include <thread>
#include <mutex>

std::mutex m;

void owns(int i) {
    std::unique_lock<std::mutex> lock(m, std::try_to_lock);
    if(lock.owns_lock())
        std::cout << "Thread " << i << ": owns mutex" << std::endl;
    else
        std::cout << "Thread " << i << ": does not own mutex" << std::endl;
}

int main() {
    {
        try {
            std::unique_lock<std::mutex>(m);
            throw std::exception();
        }

        catch(...) {
            m.lock();
            std::cout << "Exception thrown: Unique_lock released" << std::endl;
            m.unlock();
        }
    }

    std::thread t1(owns, 1);
    std::thread t2(owns, 2);

    t1.join();
    t2.join();

    return 0;
}