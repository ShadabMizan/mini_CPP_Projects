// Goal: To Validate credit card numbers using the Luhn Algorithm

// The Luhn Algorithm Follows the steps below
// 1. Double every second digit from right to left, if a doubled number is 2 digits, split them.
// 2. Add all single digits from step one.
// 3. Add all odd numbered digits from right to left.
// 4. Sum results from steps 2 and 3.
// 5. If sum is divisible by 10, then credit card is valid.

#include <iostream>
#include <array>
#include <string>

int main()
{
    //Sample credit card Number
    std::string cardNumber = "4012888888881881";
    //False sample
    // std::string cardNumber = "1897346210827339";

    //Array to hold cardNumber values. Initialized as an empty 16 integer array, so that we can apply the algorithm to it.
    std::array<int, 16> cardDigits{};

    //Convert chars in the cardNumber string into an array of integers.
    for(int i = 0; i < cardDigits.size(); i++)
    {
        int num = cardNumber[i] - '0'; //subtracting the char 0 results in the integer value for that char number.
        cardDigits[i] = num;
    }

    for(int i{cardDigits.size() - 1}; i >= 0; i--)
    {
        //If Odd:
        if(i % 2 == 1)
        {
            //Just multiply by 1 i.e. Keep it the same.
            cardDigits[i] *= 1;
        }

        //If Even:  
        else if(i % 2 == 0)
        {
            //Double that value, lets store in a temproary variable
            int temp = cardDigits[i] * 2;

            //If the double is two digits, i.e. >= 10, then split the digits and add them together.
            if(temp >= 10)
            {
                // create a string from the int so that we can split it
                std::string tempStr = std::to_string(temp);

                //Since we need to add the two digits, lets create a total variable.
                int total{0};

                //Adding the two digits together
                for(const char& num : tempStr)
                {
                    //Convert char to int
                    int number = num - '0';

                    //Add that int to the total
                    total += number;
                }

                //Putting that value into the int array
                cardDigits[i] = total;
            }

            //Since doubled value is one digit, just add it to the final cardDigits element to add together.
            else 
            {
                cardDigits[i] = temp;
            }
        }
    }

    // Final total by adding all the ints in the array
    int finalTotal{0};
    for(const int& digit : cardDigits){
        finalTotal += digit;
    }

    // Valid or not if the final is divisible by ten.
    std::cout << "Credit card "<< cardNumber << " is ";
    finalTotal % 10 == 0 ? std::cout << "VALID" : std::cout << "INVALID";

    return 0;
}