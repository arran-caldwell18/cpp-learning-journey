//Goal

//I struggled initially with the sort logic so i want to become more acoustomed to it 

#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> age = {10,22,1,45,27};

    for (size_t i = 0; i < age.size(); i++)
    {
        size_t highest_index = i;  //our highest indix is index i (so for example we started with index 0 our current higehst index is 0 then in the next iteration our highest index has moved to index 0 so our second highest index will be index pos 1)

        for (size_t j = i+1; j < age.size(); j++)   //scans the remaing unsorted students
        {
            if (age[j] > age[highest_index]) highest_index = j;     //if the index we are on is greater than the highest ¬
        }                                                           //index we have then the new highest index is j(the index we are on)
        
        //Swapping index
        int temp = age[i];
        age[i] = age[highest_index];
        age[highest_index] = temp;
    }

    for (size_t i = 0; i < age.size(); i++)
    {
        std::cout << age[i] << "\n";
    }




    return 0;

}