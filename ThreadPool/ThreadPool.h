#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "ThreadItem.h"
#include <thread>
#include <vector>
#include <functional>
#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;


class ThreadPool
{
    public:
        ThreadPool();
        virtual ~ThreadPool();
        ThreadPool(size_t numOfThreads);
        void execute(const function<void()>  &fn);

    protected:

    private:
        atomic<bool> enabled;
        mutex mut;
        condition_variable cv;
        vector<thread> workers;
        queue<reference_wrapper<const function<void()>>> tasksList;

        void run();
};

#endif // THREADPOOL_H
