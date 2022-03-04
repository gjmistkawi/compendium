#include <iostream>
#include <exception>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;

void owns(int i) {
    std::chrono::milliseconds delay(100);

    std::cout << "Thread " << i << ": started" << std::endl;
    std::this_thread::sleep_for(delay);
    
    std::lock_guard<std::mutex> lg(m);

    std::cout << "Thread " << i << ": has the mutex" << std::endl;
    std::cout << "Thread " << i << ": going out of scope" << std::endl;
}

int main() {
    {
        try {
            std::lock_guard<std::mutex> lk(m);
            throw std::exception();
        }

        catch(...) {
            m.lock();
            std::cout << "Exception thrown: Lock_guard released" << std::endl;
            m.unlock();
        }
    }

    std::thread t1(owns, 1);
    std::thread t2(owns, 2);

    t1.join();
    t2.join();

    return 0;
}