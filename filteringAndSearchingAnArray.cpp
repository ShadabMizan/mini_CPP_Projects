// Goal: to create a system that will find Prime numbers for you based on a certain range
// Learning Objective:  implement Functional-Style programming using standard library functions from ranges and numeric.
//                      implement Anonymous Functions into code.

#include <iostream>
#include <array>
#include <ranges>
#include <numeric>

#define LOWERBOUND 1
#define UPPERBOUND 2000

int main() 
{
    //Local function to output an array
    auto showNumbers{
        [](auto& values, const std::string& description)
        {
            std::cout << description << std::endl;
            for(const auto& num : values)
            {
                std::cout << num << " ";
            }
        }
    };

    //Generates these values only when called... no need to bog down memory when all values are not being used in the end.
    auto initialValues{std::views::iota(LOWERBOUND,UPPERBOUND + 1)};

    //Pipe the values into view::filter function in order to only let prime numbers through, as done with the lambda expression below
    auto primeValues
    {
        initialValues | std::views::filter(
            [](const auto& x) 
            {
                bool prime = true;
                if(x <= 2) 
                {
                    prime = false;
                } else 
                {
                    for(int i{2}; i <= x/2; ++i) 
                    {
                        if(x % i == 0) 
                        {
                            prime = false;
                        }
                    }
                }
                return prime;
            }
        )
    };

    // Use std::accumulate to sum up all the prime numbers
    auto sumOfPrimes{
        std::accumulate(
            std::begin(primeValues),
            std::end(primeValues),
            0
        )
    };

    //Print out results into terminal
    showNumbers(primeValues, "Prime Numbers Are: ");
    std::cout << std::endl << "Their sum is: " << sumOfPrimes;

    return 0;
}