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

int main() {
    Person p;
    p.setAge(17);
    p.setName("Jim");
    std::cout << p.getAge() << " " << p.getName() << "\n" << std::endl;
    p.eat();
    return 0;
}