#include <iostream>
#include <vector>



//how many numbers user wants to enter
int get_input_number(void)
{
    //our input number
    int number = 0;
    while (true)
    {
        std::cout << "How many numbers: ";
        std::cin >> number;

        if (number >= 1)
        {
            return number;
        }
        else
        {
            std::cout << "Please enter a positive number" << "\n\n";
        }
    }
}

//User integer input
int get_number(int iteration)
{   
    //where we store our number
    int number;
    //Loops over until input is revieved correctly
    while (true)
    {
        std::cout << "Enter number " << iteration << ": ";
        std::cin >> number;

        //check to see if number is positive
        if (number >= 1)
        {
            //if number is posotive then we return it
            return number;
        }
        else
        {
            std::cout << "Please enter a positive number" << "\n\n";
        }
    }
}

//getting sum of our vector
int get_sum(std::vector<int> &numbers)
{
    int sum = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        sum  += numbers[i];
    } 

    return sum;
}

//getting average of our vector
double get_average(std::vector<int> &numbers)
{
    double sum = get_sum(numbers);

    double average = sum / numbers.size();

    return average;
}

//getting largest number in vector
int get_max(std::vector<int> &numbers)
{   
    int max = 0;

    for (int i = 0; i < numbers.size(); i++)
    {   
        //if teh current number we are on is bigger than our current max
        if (numbers[i] > max)
        {
            max = numbers[i];   //we set our new max to it
        }
        //else we continue to the next iteration
    }

    return max;
}


int main(void)
{   
    //our array
    std::vector<int> total_numbers;

    //get how many iterations / the number of times we want to ask for a number
    int iterations = get_input_number();

    //get numbers and add them to vector
    for (int i = 0; i < iterations; i++)
    {
        total_numbers.push_back(get_number(i+1));   //plus one so we staart on 1 not 0
    }
    
    //finding the sum of our numbers
    int sum = get_sum(total_numbers);
    double average = get_average(total_numbers);
    int max = get_max(total_numbers);

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Average: " << average << "\n";
    std::cout << "Max: " << max << "\n";

    return 0;
}