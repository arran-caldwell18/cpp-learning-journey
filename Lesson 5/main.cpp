#include <iostream>
#include <string>

//get user input for a number
int get_number()
{
    int number;

    while (true)
    {
        std::cout << "Enter number: ";
        std::cin >> number;

        if (number >= 1)
            return number;

        std::cout << "Please enter a positive number\n";
    }
}

int main(void)
{
    //get number
    int num = get_number();

    for (int i = 0; i < num; i++)
    {
        //i + 1 so we dont start from 0 and we finish on the given number
        std::cout << i+1 << "\n";
    }

    return 0;
}