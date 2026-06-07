#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort

//---Structs---
struct Student
{
    std::string name;
    int age;
    double grade;
};

//---Functions---

//--sort vector by grades
void manual_sort_by_grade(std::vector<Student>& classroom)
{
    for (size_t i = 0; i < classroom.size(); i++)   //variable i represents the current slot we are trying to fill with the next highest grade.
    {
        size_t highest_index = i;   //Before looking at the rest of the students, we assume that the student currently at position i has the highest grade

        for (size_t j = i + 1; j < classroom.size(); j++)   //This loop scans the remaining unsorted students. There is no need to look at positions before i because those have already been correctly sorted in previous turns.
        {
            if (classroom[j].grade > classroom[highest_index].grade)//We look at the student at index j. If their grade is greater (>) than the grade of the student at our current highest_index, it means we've found someone with a higher grade
            { 
                highest_index = j;  //We update highest_index to point to this new, better position. Crucially, we do not swap yet. We just finish the loop to make sure no one else has an even higher grade.
            }
        }

        //Swap the current element with the highest one found
        Student temp = classroom[i];
        classroom[i] = classroom[highest_index];
        classroom[highest_index] = temp;
    }
}


//---Main Loop---
int main(void)
{
    //--Vector Creation--
    std::vector<Student> classroom_1;

    //--Manually Filling In Classroom vector--
    classroom_1.push_back({"Alice", 15, 87.5});
    classroom_1.push_back({"Ben", 16, 92.0});
    classroom_1.push_back({"Charlie", 15, 78.3});
    classroom_1.push_back({"Daisy", 16, 95.8});
    classroom_1.push_back({"Ethan", 15, 81.4});
    classroom_1.push_back({"Fiona", 16, 89.7});
    classroom_1.push_back({"George", 15, 73.2});
    classroom_1.push_back({"Hannah", 16, 98.1});

    //Manually sorting by grade
    manual_sort_by_grade(classroom_1);
    for (size_t i = 0; i < classroom_1.size(); i++)
    {
        std::cout << classroom_1[i].name << ": " << classroom_1[i].grade << "\n";
    }

    //Spacer
    std::cout << "\n\n\n";

    //--Vector Creation--
    std::vector<Student> classroom_2;

    //--Manually Filling In Classroom vector--
    classroom_2.push_back({"Alice", 15, 87.5});
    classroom_2.push_back({"Ben", 16, 92.0});
    classroom_2.push_back({"Charlie", 15, 78.3});
    classroom_2.push_back({"Daisy", 16, 95.8});
    classroom_2.push_back({"Ethan", 15, 81.4});
    classroom_2.push_back({"Fiona", 16, 89.7});
    classroom_2.push_back({"George", 15, 73.2});
    classroom_2.push_back({"Hannah", 16, 98.1});



    //Using C++ built in method
    // Use std::sort with a manual lambda comparison
    std::sort(classroom_2.begin(), classroom_2.end(), [](const Student& a, const Student& b) {return a.grade > b.grade;});  // '>' sorts in descending order (highest grade first)
    for (size_t i = 0; i < classroom_2.size(); i++)
    {
        std::cout << classroom_2[i].name << ": " << classroom_2[i].grade << "\n";
    }

    return 0;
}