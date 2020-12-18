//
// Created by apurv on 14/12/20.
//

// C++ program to demonstrate shared_ptr
#include <iostream>
#include <memory>
using namespace std;

class Apurv {
public:
    static void output()
    {
        cout << "Value for pointer" << endl;
    }
};

int main()
{
    //Create a Shared Pointer
    shared_ptr<Apurv> p1(new Apurv);
    cout << "Memory Address for 1st Pointer" << p1.get() << endl;
    p1->output();

    //Create a Second Shared Pointer
    shared_ptr<Apurv> p2(p1);
    p2->output();
    cout << "Memory Address for 1st Pointer - " << p1.get() << endl;
    cout << "Memory Address for 2nd Pointer - " << p2.get() << endl;
    cout << "Reference counter for 1st Pointer - " << p1.use_count() << endl;
    cout << "Reference counter for 2nd Pointer - " << p2.use_count() << endl;
    p1.reset();
    cout << "Memory Address for 1st Pointer - " << p1.get() << endl;
    cout << "Reference counter for 2nd Pointer - " << p2.use_count() << endl;
    cout << "Memory Address for 2nd Pointer - " << p2.get() << endl;

    return 0;
}
