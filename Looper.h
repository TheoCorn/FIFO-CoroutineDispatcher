//
// Created by theo on 5/22/2021.
//

#ifndef LOOPER_LOOPER_H
#define LOOPER_LOOPER_H

#include "mtlNamespce.h"
#include "Queue.h"
#include <thread>
#include <atomic>
#include <memory>
#include <functional>
#include <stdexcept>

    class mtl::Looper {
    public:
        Looper();
        ~Looper();

        bool run();
        void stop();
        void add(Runnable* item);
        bool isRunning();
        void stopAndJoin();

    private:
        Queue* runnablesQ;
        std::thread mThread;

        std::atomic_bool mRunning;
        std::atomic_bool mStopRequest;

        void looperFunction();

    };







#endif //LOOPER_LOOPER_H
