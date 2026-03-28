#ifndef PEASON_H
#define PEASON_H

#include <iostream>
#include <string>

class Person {
public:
    void eat() {
        std::cout << name << " is eating. He is " << age << " years old.\n" << std::endl;
    }
    int getAge() { return age; }
    std::string getName() { return name; }
    void setAge(int a) { age = a; }
    void setName(std::string n) { name = n; }
private:
    int age;
    std::string name;
};

#endif // PEASON_H