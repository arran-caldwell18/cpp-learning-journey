#include <iostream>
#include <vector>
#include <string>

//creating our stuident strucy
struct Student
{
    std::string name;
    int age;
    double grade;
};

Student get_input(Student& pupil)
{   
    //starting try block
    std::cout <<  "Enter students name: ";
    std::getline(std::cin , pupil.name);

    return pupil;
    
}


double get_average_grade(const std::vector<Student>& classroom)
{   
    double sum = 0;
    for (size_t i = 0; i < classroom.size(); i++)
    {
        sum += classroom[i].grade;
    }

    return sum / classroom.size();
}

Student get_highest_grade(const std::vector<Student>& classroom)
{
    Student highest_grade = classroom[0];

    for (size_t i = 0; i < classroom.size(); i++)
    {
        if (classroom[i].grade > highest_grade.grade) highest_grade = classroom[i];
    }

    return highest_grade;
}   

Student get_youngest_student(const std::vector<Student>& classroom)
{
    Student youngest = classroom[0];

    for (size_t i = 0; i < classroom.size(); i++)
    {
        if (classroom[i].age < youngest.age) youngest = classroom[i];
    }

    return youngest;
}  

bool find_student(const std::vector<Student>& classroom , const std::string target)
{
    for (size_t i = 0; i < classroom.size(); i++)
    {
        if (classroom[i].name == target) return true;
    }

    return false;
}

int main(void)
{
    //A vector full of students
    std::vector<Student> classroom;

    //adding a load of students
    classroom.push_back({"Alice", 15, 87.5});
    classroom.push_back({"Ben", 16, 92.0});
    classroom.push_back({"Charlie", 15, 78.3});
    classroom.push_back({"Daisy", 16, 95.8});
    classroom.push_back({"Ethan", 15, 81.4});
    classroom.push_back({"Fiona", 16, 89.7});
    classroom.push_back({"George", 15, 73.2});
    classroom.push_back({"Hannah", 16, 98.1});


    //anylising
    double average_grade = get_average_grade(classroom);
    Student highest_grade = get_highest_grade(classroom);
    Student youngest = get_youngest_student(classroom);

    Student target; 
    target = get_input(target);

    bool found_student = find_student(classroom , target.name);
    std::string verdict;
    if (found_student == true) verdict = "is"; else verdict = "is not";

    //printing results
    std::cout << "Average grade: " << average_grade << "\n\n";
    std::cout << "Highest grade: " << "\n" << "Name: " << highest_grade.name << "\n" << "Grade: " << highest_grade.grade << "\n\n";
    std::cout << "Youngest Student:" << "\n" << "Name: " << youngest.name << "\n" << "Age: " << youngest.age << "\n\n";
    std::cout << target.name << " " << verdict << " in the class!" << std::endl;

    return 0;
}

