//
// Created by theo on 5/22/2021.
//

#include "Runnable.h"
#include <functional>
#include <utility>

mtl::Runnable::Runnable(std::function<void(void *)> fun, void *funArg, bool destroy) {
    timeout = -1;
    this->fun = std::move(fun);
    this->funArg = funArg;
    this->destroy = destroy;

}


mtl::Runnable::Runnable(std::function<void(void *)> fun, void *funArg, void *desFunArg,
                        std::function<void(void *)> desFun, bool destroy) {
    timeout = -1;
    this->fun = std::move(fun);
    this->destructorFun = std::move(desFun);
    this->funArg = funArg;
    destructorFunArg = desFunArg;
    this->destroy = destroy;

}

mtl::Runnable::Runnable(std::function<void(void *)> fun, void *funArg, long timeout, bool destroy) {
    this->fun = std::move(fun);
    this->timeout = timeout;
    this->funArg = funArg;
    this->destroy = destroy;
}

mtl::Runnable::Runnable(std::function<void(void *)> fun, void *funArg, std::function<void(void *)> desFun, void *desFunArg,
                        long timeout, bool destroy) {

    this->timeout = timeout;
    this->fun = std::move(fun);
    this->destructorFun = std::move(desFun);
    this->funArg = funArg;
    destructorFunArg = desFunArg;
    this->destroy = destroy;

}


mtl::Runnable::~Runnable() {
    if (destructorFun != nullptr){
        destructorFun(destructorFunArg);
    }
}

long mtl::Runnable::getTimeout() const {
    return timeout;
}

bool mtl::Runnable::hasTimeout() const {
    return timeout != -1;
}

void *mtl::Runnable::getArgument() const {
    return funArg;
}

std::function<void(void*)> mtl::Runnable::getFunction() const{
    return fun;
}

bool mtl::Runnable::destroyMe() const {
    return destroy;
}
