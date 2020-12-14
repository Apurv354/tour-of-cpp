//
// Created by apurv on 14/12/20.
//

#include <iostream>
#include <string>
#include <memory>

class Person
{
    std::string m_name;
    std::shared_ptr<Person> m_partner; // initially created empty
    std::weak_ptr<Person> w_partner; // initially created empty

public:

    Person(const std::string &name): m_name(name)
    {
        std::cout << m_name << " created\n";
    }
    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->w_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

        return true;
    }
};

int main()
{
    auto lucy = std::make_shared<Person>("Lucy"); // create a Person named "Lucy"
    std::cout << "use_count() == " << lucy.use_count() << '\n';

    {
        auto ricky = std::make_shared<Person>("Ricky"); // create a Person named "Ricky"
        std::cout << "use_count() == " << ricky.use_count() << '\n';

        {
            partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa
            std::cout << "1 lucy == " << lucy.use_count() << '\n';
            std::cout << "1 ricky == " << ricky.use_count() << '\n';
        }
        std::cout << "2 lucy == " << lucy.use_count() << '\n';
        std::cout << "2 ricky == " << ricky.use_count() << '\n';

    }
    std::cout << "3 lucy == " << lucy.use_count() << '\n';

    return 0;
}
