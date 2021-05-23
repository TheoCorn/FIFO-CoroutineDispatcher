//
// Created by theo on 5/22/2021.
//

#include "Looper.h"
#include <thread>
#include <atomic>
#include <iostream>

mtl::Looper::Looper() {
    mRunning.store(false);
    mStopRequest.store(false);
    runnablesQ = new Queue();
}

mtl::Looper::~Looper() {
    delete runnablesQ;
}

void mtl::Looper::add(mtl::Runnable* item) {
    runnablesQ->push(item);
}

void mtl::Looper::stop() {
    mStopRequest.store(true);
}

bool mtl::Looper::run() {
    try {
        mThread = std::thread(&Looper::looperFunction, this);
    }catch (...){
        return false;
    }
    return true;
}

void mtl::Looper::looperFunction() {
    mRunning.store(true);

    while(!mStopRequest.load()){

        try {

            if(auto item = runnablesQ->pop()){
                reinterpret_cast<Runnable*>(item.value())->getFunction()(reinterpret_cast<Runnable*>(item.value())->getArgument());
                if(reinterpret_cast<Runnable*>(item.value())->destroyMe()) delete reinterpret_cast<Runnable*>(item.value());

            }
        }catch(...){}
    }

    mRunning.store(false);
}

bool mtl::Looper::isRunning() {
    return mRunning.load();
}

void mtl::Looper::stopAndJoin() {
    mStopRequest.store(true);
    if(mThread.joinable()) mThread.join();
}


