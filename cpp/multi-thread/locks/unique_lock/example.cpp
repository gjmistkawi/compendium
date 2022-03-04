#include <iostream>
#include <exception>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;

void owns(int i) {
    std::chrono::milliseconds delay(100);

    std::unique_lock<std::mutex> lock(m, std::try_to_lock);
    if(lock.owns_lock()) {
        std::cout << "Thread " << i << ": locked mutex" << std::endl;
        std::this_thread::sleep_for(delay);
        lock.unlock();
        std::cout << "Thread " << i << ": unlocked mutex\n";
        std::this_thread::sleep_for(delay);
        lock.lock();
        std::cout << "Thread " << i << ": locked mutex" << std::endl;
        std::cout << "Thread " << i << ": end of thread" << std::endl;
    }

    else {
        std::cout << "Thread " << i << ": does not own mutex" << std::endl;
        lock.lock();
        std::cout << "Thread " << i << ": locked mutex\n";
        lock.unlock();
        std::cout << "Thread " << i << ": unlocked mutex\n";
        std::this_thread::sleep_for(delay);
        std::cout << "Thread " << i << ": end of thread" << std::endl;
    }
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