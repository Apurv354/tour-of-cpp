//
// Created by apurv on 18/12/20.
//

#include <iostream>
#include <thread>

static bool s_finish = false;

void Duty()
{
    using namespace std::literals::chrono_literals;
    while (!s_finish) {
        std::cout << "We are alive \n";
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(Duty);
    std::cin.get();
    s_finish = true;
    worker.join();

    std::cin.get();
}