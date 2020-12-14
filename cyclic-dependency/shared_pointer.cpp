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
        cout << "Value::show()" << endl;
    }
};

int main()
{
    shared_ptr<Apurv> p1(new Apurv);
    cout << p1.get() << endl;
    p1->output();
    shared_ptr<Apurv> p2(p1);
    p2->output();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    p1.reset();
    cout << p1.get() << endl;
    cout << p2.use_count() << endl;
    cout << p2.get() << endl;

    return 0;
}
