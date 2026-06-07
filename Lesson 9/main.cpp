#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // Required for standard exceptions    (i search up how u would catch error in Cpp)


int get_input(std::string message = "How many numbers? ")
{
    int number;
    while (true)
    {      
        //starting try block
        try{
            std::cout << message;
            std::cin >> number;

            //check to see if its positive
            if (number >= 1)
            {
                return number;
            }
            else
            {
                throw std::logic_error("number cannot be negative!");   //throwing a logic error with the message -->> number cannot be negative!
            }
            
        }
        //catching error
        catch (const std::logic_error& e)   //catches the logic error we threw and stores the message in the variable e (&e so the location is storage the error message is saved in)
        {
            std::cerr << "Error caught: " << e.what() << "\n";      //printing that we caught the error and e.what() that prints the error message stored in memory location e (number cannot be negative!)
        }
    }
}


int get_number(int iteration)
{
    int number;
    while (true)
    {      
        //starting try block
        try{
            std::cout << "Enter number " << iteration << ": ";
            std::cin >> number;

            //check to see if its positive
            if (number >= 1)
            {
                return number;
            }
            else
            {
                throw std::logic_error("number cannot be negative!");   //throwing a logic error with the message -->> number cannot be negative!
            }
            
        }
        //catching error
        catch (const std::logic_error& e)   //catches the logic error we threw and stores the message in the variable e (&e so the location is storage the error message is saved in)
        {
            std::cerr << "Error caught: " << e.what() << "\n";      //printing that we caught the error and e.what() that prints the error message stored in memory location e (number cannot be negative!)
        }
    }
}

int count_occurences(const std::vector<int>& numbers , int target)
{   
    int target_count = 0;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == target)
        {
            target_count += 1;
        }
    }

    return target_count;
}

void most_common(const std::vector<int>& numbers , int& common_number , int& appear )
{   
    //max occurences
    int max_occurences = 0;
    int max_occurences_number = numbers[0];

    for (size_t i = 0; i < numbers.size(); i++)
    {   
        int occurences = count_occurences(numbers , numbers[i]);
        if (occurences > max_occurences)
        {
            max_occurences = occurences;
            max_occurences_number = numbers[i];
        }
    }

    common_number = max_occurences_number;
    appear = max_occurences;
}

int main(void)
{
    //setting variables
    int iterations = get_input();
    std::vector<int> total_numbers;


    //Filling the vector
    for (int i = 0; i < iterations; i++)
    {
        total_numbers.push_back(get_number(i+1));
    }

    //get user target
    int target = get_input("Enter a number to count occurences for: ");
    int occur = count_occurences(total_numbers , target);

    //find most common number
    int most_common_number;
    int most_common_number_appearences;
    most_common(total_numbers , most_common_number , most_common_number_appearences);

    std::cout << target << " appears " << occur << " times" << "\n";
    
    std::cout << "Most common number: " << most_common_number << "\n";
    std::cout << "Occurrences: " << most_common_number_appearences << "\n";
    
    return 0;
}