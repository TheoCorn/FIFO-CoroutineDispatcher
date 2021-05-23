//
// Created by theo on 5/22/2021.
//

#ifndef LOOPER_RUNNABLE_H
#define LOOPER_RUNNABLE_H

#include "mtlNamespce.h"
#include <functional>

class mtl::Runnable {
private:
    long timeout;
    std::function<void(void*)> fun;
    std::function<void(void*)> destructorFun;

    void* funArg;
    void* destructorFunArg{};
    void* runnableArg{};

    bool destroy = true;


public:

    Runnable(std::function<void(void *)> fun, void *funArg, bool destroy = true);
    Runnable(std::function<void(void*)> fun, void *funArg, long timeout, bool destroy = true);
    Runnable(std::function<void(void *)> fun, void *funArg, void *desFunArg,
             std::function<void(void *)> desFun, bool destroy = true);
    Runnable(std::function<void(void*)> fun, void *funArg, std::function<void(void*)>desFun, void* desFunArg, long timeout, bool destroy = true);
    ~Runnable();

    [[nodiscard]] bool hasTimeout() const;
    [[nodiscard]] long getTimeout() const;
    [[nodiscard]] std::function<void(void*)> getFunction() const;
    [[nodiscard]] void* getArgument() const;
    [[nodiscard]] bool destroyMe() const;


};


#endif //LOOPER_RUNNABLE_H
