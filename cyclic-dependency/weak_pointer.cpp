//
// Created by apurv on 14/12/20.
//

// TO access a deleted ptr

#include <iostream>
#include <memory>

void report(std::shared_ptr<int> ptr)
{
    if (ptr) {
        std::cout << "*ptr=" << *ptr << "\n";
    } else {
        std::cout << "ptr is not a valid pointer.\n";
    }
}

int main()
{
    std::shared_ptr<int> ptr;
    report(ptr);

    ptr = std::make_shared<int>(7);
    report(ptr);
}