//Goal
//Master Insertion sort

//---Inlcuding libarys---
#include <iostream>
#include <vector>

//---Main Loop---
int main(void)
{   
    //creation of vector
    std::vector<double> heights = {123.4, 175.3, 180.0, 97.95};

    //--Insertion sort--
    for (int i = 1; i < heights.size(); i++)
    {
        double key = heights[i];
        int j = i - 1;

        while (j >= 0 && heights[j] > key)
        {
            heights[j + 1] = heights[j]; // shift right
            j--;    //removing 1 from our index
        }

        heights[j + 1] = key; // insert
    }


    //--print--
    for (int i = 0; i < heights.size(); i++)
    {
        std::cout << heights[i] << "\n";
    }

}