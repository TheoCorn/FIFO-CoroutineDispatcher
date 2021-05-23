//
// Created by theo on 5/22/2021.
//

#include "Queue.h"
#include "Runnable.h"
#include "mtlNamespce.h"
#include <queue>
#include <mutex>
#include <optional>
#include <functional>
#include "Runnable.h"

bool mtl::Queue::empty() {
    return runnablesQ.empty();
}

unsigned long mtl::Queue::size() const {
    std::lock_guard<std::mutex> lock(qMutex);
    return runnablesQ.size();
}

std::optional<void*> mtl::Queue::pop() {
    std::lock_guard<std::mutex> lock(qMutex);
    if (runnablesQ.empty()) return {};

    Runnable* tmp = runnablesQ.front();
    runnablesQ.pop();
    return (void*)tmp;
}

void mtl::Queue::push(mtl::Runnable *item) {
    std::lock_guard<std::mutex> lock(qMutex);
    runnablesQ.push(item);
}
