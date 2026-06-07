//Using Vector/ Arrays

#include <iostream>
#include <vector>

//get users number
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
    int num = get_number();
    int sum = 0;

    std::vector<int> total_num;

    for (int i = 0; i < num; i++)
    {
        total_num.push_back(i+1);
        sum += i+1;
    }

    for (int i = total_num.size() - 1; i >= 0; i--) //i = the size of total num - 1. then we stop when u >= 0 then we minus from i until we go thru the totaal num
    {
        std::cout << total_num[i] << "\n";  //use indexing from the vector
    }

    std::cout << "Sum " << sum << "\n";

    return 0;
}