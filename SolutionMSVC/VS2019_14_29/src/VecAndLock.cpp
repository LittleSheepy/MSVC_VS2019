//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//
//std::vector<int> myVector;
//std::mutex myMutex;
//
//void threadFunction(int threadID) {
//    myMutex.lock();
//    std::cout << "Thread " << threadID << " is adding elements to the vector." << std::endl;
//    for (int i = 0; i < 100; i++) {
//        myVector.push_back(i);
//    }
//    myMutex.unlock();
//}
//
//void VecAndLock() {
//    std::thread t1(threadFunction, 1);
//    std::thread t2(threadFunction, 2);
//
//    t1.join();
//    t2.join();
//
//    myMutex.lock();
//    std::cout << "The final size of the vector is: " << myVector.size() << std::endl;
//    myMutex.unlock();
//}
#include <iostream>
#include <vector>
#include <thread>
#include <shared_mutex>

std::vector<int> myVector;
std::shared_mutex myMutex;

void threadFunction(int threadID) {
    std::cout << "Thread " << threadID << " is adding elements to the vector." << std::endl;
    for (int i = 0; i < 1000; i++) {
        std::unique_lock<std::shared_mutex> lock(myMutex);
        myVector.push_back(i);
    }
}

int VecAndLock() {
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);

    t1.join();
    t2.join();

    std::shared_lock<std::shared_mutex> lock(myMutex);
    std::cout << "The final size of the vector is: " << myVector.size() << std::endl;

    return 0;
}