//
// Created by theo on 5/22/2021.
//

#ifndef LOOPER_QUEUE_H
#define LOOPER_QUEUE_H

#include "mtlNamespce.h"
#include <queue>
#include <mutex>
#include <optional>
#include <functional>
#include "Runnable.h"


class mtl::Queue {
private:
    std::queue<Runnable*> runnablesQ;
    mutable std::mutex qMutex;

    bool empty();

public:
    Queue() = default;
    virtual ~Queue() = default;

    unsigned long size() const;
    std::optional<void*> pop();
    void push(Runnable* item);

};


#endif //LOOPER_QUEUE_H
