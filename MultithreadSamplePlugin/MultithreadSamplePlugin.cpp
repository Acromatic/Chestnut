// MultithreadSamplePlugin.cpp
// 
// ATTENTION: This is not a normal "multithreaded plugin" rather it is an example of using multithreading INSIDE of a multithreaded plugin.
// EXAMPLE METHOD if you want to multithread your applications as well, just be aware if they communicate with other plugins with threading you may encounter unforeseen issues
// 
// The plugins themselves are multithreaded
// However, it's possible to multithread and maximize core usage within the plugins themselves as well
// In this Sample-Chestnut-Plugin we show how this can be achieved with std::thread

#include "IPlugin.h"
#include <iostream>
#include <thread> // Added include for std::thread

class MultithreadSamplePlugin : public IPlugin {
public:
    using Clock = std::chrono::high_resolution_clock;
    using Duration = std::chrono::duration<double>;

    void process() override {
        std::cout << "MultithreadSamplePlugin: Starting processing" << std::endl;

        // Delta timing 
        auto startTime = Clock::now();

        // Create two additional threads for concurrent processing
        std::thread thread_1([this]() {
            processTask(1);
            });

        std::thread thread_2([this]() {
            processTask2(2);
            });

        // Track the thread id's before and after processing
        std::thread::id thread_1_id = thread_1.get_id();
        std::thread::id thread_2_id = thread_2.get_id();

        std::cout << "Thread 1's Starting ID: " << thread_1_id << ", Thread 2's Starting ID: " << thread_2_id << std::endl;

        // Wait for the threads to finish
        thread_1.join();
        auto endTime1 = Clock::now();
        Duration delta1 = endTime1 - startTime;

        std::cout << "Delta time: Thread [" << thread_1_id << "] took " << delta1.count() << " seconds" << std::endl;

        thread_2.join();
        auto endTime2 = Clock::now();
        Duration delta2 = endTime2 - startTime;

        std::cout << "Delta time: Thread [" << thread_2_id << "] took " << delta2.count() << " seconds" << std::endl;

        std::cout << "MultithreadSamplePlugin: Processing completed" << std::endl;
    }

private:
    void processTask(int threadId) {
        std::cout << "Processing task with id " << threadId << std::endl;

        // Additional processing for task 1
    }

    void processTask2(int threadId2) {
        std::cout << "Processing task with id " << threadId2 << std::endl;

        // Additional processing for task 2
    }
};

// Export the plugin instance
extern "C" {
    __declspec(dllexport) IPlugin* createPlugin() {
        return new MultithreadSamplePlugin();
    }

    __declspec(dllexport) void destroyPlugin(IPlugin* plugin) {
        delete plugin;
    }
}
