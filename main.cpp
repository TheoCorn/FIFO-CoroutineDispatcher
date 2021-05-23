#include <iostream>
#include "Looper.h"
#include "Runnable.h"
#include <functional>
#include <chrono>
#include <thread>
#include <string>

void print(void* arg){
    std::cout<< *reinterpret_cast<std::string*>(arg) <<std::endl;
    delete reinterpret_cast<std::string*>(arg);
}

int main() {
    mtl::Looper looper;
    std::function<void(void *)> fun = print;


    for (int i = 0; i < 100; ++i) {
        std::string str = std::to_string(i);
        mtl::Runnable runnable(fun, &str, true);
        looper.add(&runnable);
    }


    looper.run();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    looper.stopAndJoin();

}

