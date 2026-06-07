#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> age = {10,2,5,15,64};

    //-Sorting-
    for (size_t i = 0; i < age.size();  i++)
    {
        size_t highest_index = i;   //current highest index 

        for (size_t j = i+1 ; j < age.size(); j++)  //loops throught our unsorted part of vector by contining from i (+1 so we dont also sort the index we are on)
        {
            if (age[j] > age[highest_index]) highest_index = j; //remeber j not j[age]
        }

        //swap
        size_t temp = age[i];       //use because size_t is a Cpp unique unsigned variable which mens it is alwyas big enuf and is used to hold the size of any object in memory
        age[i] = age[highest_index];
        age[highest_index] = temp;
    }

    for (size_t i = 0; i < age.size(); i++)
    {
        std::cout << age[i] << "\n";
    }

    return 0;
}