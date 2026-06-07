#include <iostream>
#include <string>

//using a struct which defines a person
struct Person
{
    std::string name;
    int age;
    double height;
};

int main(void)
{
    //instead of adding to varaible names we add to struct (i know structs from C but it prob isnt propper c++ syntax using all of the tricks in C++)
    Person person;
    person.name = "Arran";
    person.age = 14;
    person.height = 172.72;

    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age: " << person.age << std::endl;
    std::cout << "height: " << person.height << "cm" << std::endl;

    return 0;
}