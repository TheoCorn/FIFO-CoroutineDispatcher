#include <iostream>
#include "Looper.h"
#include "Runnable.h"
#include <functional>
#include <chrono>
#include <thread>
#include <string>

void print(void* arg){
//    std::cout<< *reinterpret_cast<std::string*>(arg) <<std::endl;
//    delete reinterpret_cast<std::string*>(arg);

    std::cout<<"runnable" <<std::endl;
}

int main() {
    mtl::Looper looper;
    std::function<void(void *)> fun = print;

    auto runnable = new mtl::Runnable(fun, nullptr, true);
    looper.add(runnable);


//    for (int i = 0; i < 100; ++i) {
//        mtl::Runnable runnable(fun, nullptr, true);
////        std::string str = std::to_string(i);
//        looper.add(&runnable);
//    }


    looper.run();
    std::this_thread::sleep_for(std::chrono::seconds(60));
    looper.stopAndJoin();

}


