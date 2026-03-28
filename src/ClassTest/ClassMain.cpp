#include <iostream>
#include <string>
#include "Person.h"

int main() {
    Person p;
    p.setAge(17);
    p.setName("Jim");
    std::cout << p.getAge() << " " << p.getName() << "\n" << std::endl;
    p.eat();
    return 0;
}