//Goal:
//
//User input

#include <iostream>
#include <string>

//setting as current yeara
const int CURRENT_YEAR = 2026;

struct Person
{
    std::string name;
    int age;
    double height;
};

//very similar structure just changes that it reads the whole line
void get_name(Person &person)  
{
    //get user name and save it to the person
    std::cout << "Enter Name: " << std::endl;   //prompt the User
    std::getline(std::cin , person.name);    //get the users name from user and then save it in person.name
}

void get_age(Person &person)
{
    //get user name and save it to the person
    std::cout << "Enter Age: " << std::endl; ;
    std::cin >> person.age; 
}

void get_height(Person &person)
{
    //get user name and save it to the person
    std::cout << "Enter Height: " << std::endl;
    std::cin >> person.height;
}

int main(void)
{   
    //creating a new person
    Person person;

    //running all funcs to get persons data
    get_name(person);
    get_age(person);
    get_height(person);

    int birth_year = CURRENT_YEAR - person.age;

    //printing data
    std::cout << "Hello " << person.name << std::endl;
    std::cout << "You are " << person.age << " years old" << std::endl;
    std::cout << "Your height is " << person.height << "cm" << std::endl;
    std::cout << "You were born in " << birth_year << std::endl;

    return 0;
}