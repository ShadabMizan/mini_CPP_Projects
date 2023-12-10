#include <iostream>
#include <chrono>
#include "infint/InfInt.h"

using namespace std::chrono;

InfInt fibC{1};
InfInt fibP{0};
int indexC{1}; 
int indexP{0}; 

InfInt fibonacci(long n, InfInt& fibCurrent, InfInt& fibPrevious, int& indexCurrent, int& indexPrevious);

int main()
{
    // Section 1. Ask the User for a fibonacci subscript to calculate. Only accepts increasing subscripts.
    int subscript{-1};
    for(int n; std::cout << "Enter a subscript in increasing order, and -1 to exit: ", std::cin >> n, n != -1;)
    {
        if(n <= subscript)
        {
            std::cout << "Invalid subscript! Starting Section 2..." << std::endl;
            break;
        }
        subscript = n;
        std::cout << fibonacci(subscript, fibC, fibP, indexC, indexP) << std::endl;
    }

    // Section 2. Find the maximum fibonacci number your machine can calculate in 4 seconds.
    const int runLimit{4};

    //Start time
    time_point<steady_clock> start = steady_clock::now();

    //End Time
    time_point<steady_clock> endTime = runLimit*1s + start;

    //do-while running until 4 seconds are over.
    do {
        fibonacci(++subscript, fibC, fibP, indexC, indexP); // eventually substitute in this line for the one above
    } while(steady_clock::now() < endTime); 

    // Output the highest Fibonacci subscript calculated
    std::cout << "Highest subscript gone up to: " << subscript << std::endl;
    std::cout << "Equals: " << std::endl << fibonacci(subscript, fibC, fibP, indexC, indexP) << std::endl;
    return 0;
}

InfInt fibonacci(long n, InfInt& fibCurrent, InfInt& fibPrevious, int& indexCurrent, int& indexPrevious)
{
    //Four global variables that need to be changed over calculations
	fibC = fibCurrent;
	fibP = fibPrevious;
	indexC = indexCurrent;
	indexP = indexPrevious;

    //0 and 1 Base cases
	if(n <= 1)
    {
		return n;
	}

    //Creating new base cases that we've calculated
	if(n == indexC)
    {
		return fibC;
	} 
    else if(n == indexP)
    {
		return fibP;
	}

    //Otherwise, we are going to need to create new values for fibC and fibP every time they don't already exist.
	//  This will be stored in a temporary variable that is non-static

	InfInt tempFibPP = fibonacci(n - 2, fibC, fibP, indexC, indexP);
	InfInt tempFibP = fibonacci(n - 1, fibC, fibP, indexC, indexP);
	InfInt tempFibC = tempFibPP + tempFibP;

	//Now shift these temporary variable values to the static variable.

	fibP = tempFibP;
	fibC = tempFibC;

	//Remember, indexes will change once u change the values of fibC and fibP.
	//  Since this is a top-down approach, f(5) would become f(4) and f(3)
	//  This means that indexes will shift down one value.
	indexC = n;
	indexP = n - 1;

	//Now, you can return fibC
	return fibC;
}