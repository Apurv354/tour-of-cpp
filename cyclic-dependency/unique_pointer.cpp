// Change the ownership of a unique pointer

#include <iostream>
#include <memory>

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    std::unique_ptr<Resource> res1{ new Resource{} }; // Resource created here
    std::unique_ptr<Resource> res2{}; // Start as nullptr

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

    // res2 = res1; // Won't compile: copy assignment is disabled
    res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null\n" : "null\n");
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null\n" : "null\n");

    return 0;
}