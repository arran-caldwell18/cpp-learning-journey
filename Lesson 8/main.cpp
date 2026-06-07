#include <iostream>
#include <vector>
#include <string>

int get_input_number(std::string message = "How many numbers? ")
{
    int number;
    while (true)
    {
        std::cout << message;
        std::cin >> number;

        //check to see if its positive
        if (number >= 1)
        {
            return number;
        }
        else
        {
            std::cout << "Please enter a posotive number" << "\n\n";
        }
    }
}

int get_input(int iteration)
{
    int number;
    while (true)
    {
        std::cout << "Enter number " << iteration << ": ";
        std::cin >> number;

        //check to see if its positive
        if (number >= 1)
        {
            return number;
        }
        else
        {
            std::cout << "Please enter a posotive number" << "\n\n";
        }
    }
}

int get_min(const std::vector<int>& numbers) //cosnt this time so just in case we acidently do we can not change anything
{
    int min = numbers[0];

    for (size_t i = 0; i < numbers.size(); i++) //Using size_t i think this is how it works
    {
        if (min > numbers[i])
        {
            min = numbers[i];
        }
    }

    return min;
}

int count_even(const std::vector<int>& numbers)
{   
    //count
    int count = 0;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            count += 1;
        }
    }

    return count;
}

int count_odd(const std::vector<int>& numbers)
{   
    //count
    int count = 0;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 != 0)
        {
            count += 1;
        }
    }

    return count;
}

bool contains_number(const std::vector<int>& numbers , int search)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == search)
        {
            return true;
        }
    }
    
    return false;
}

int main(void)
{
    //setting variables
    int iterations = get_input_number();
    std::vector<int> total_numbers;



    //Filling the vector
    for (int i = 0; i < iterations; i++)
    {
        total_numbers.push_back(get_input(i+1));
    }



    //find number in list
    int search = get_input_number("Enter a number to search for: ");
    bool contains_search = contains_number(total_numbers , search);
    std::string verdict;

    //formating into a clean results
    if (contains_search == true) verdict = "does"; else verdict = "does not";



    //anylising numbers
    int min = get_min(total_numbers);
    int even_count = count_even(total_numbers);
    int odd_count = count_odd(total_numbers);

    //printing results
    std::cout << "The vector " << verdict << " contain the number " << search << "\n";
    std::cout << "Min: " << min << "\n";
    std::cout << "Odd: " << odd_count << "\n";
    std::cout << "Even: " << even_count << "\n";

    return 0;
}