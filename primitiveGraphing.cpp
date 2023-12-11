// Goal: to convert numerical values representing ratings on a 5-star scale into a bar graph representation in the terminal
// Learning Objective:  Build Arrays based on the standard library array, and use its built in functions
//                      Implement the type size_t
//                      Implement constexpr to set an Array's size during compile time.
#include <iostream>
#include <array>
#include <iomanip>

// Main array I am working with to convert into graphical representation. Feel free to input any 5 integers to represent the number of ratings.
constexpr std::array<size_t, 5> ratings = {
    25,     //5 Star
    12,     //4 Star
    4,      //3 Star
    5,      //2 Star
    2       //1 Star
};

//Obtains the maximum value from the ratings array, thus determining the length of the bar graph.
constexpr size_t getMaxRatingLength(const std::array<size_t, 5>& ratings)
{
    size_t maxGraphLength{0};

    //look for the largest number of reviews
    for(size_t i{0}; i < ratings.size(); ++i)
    {
        if(maxGraphLength <= ratings[i])
        {
            maxGraphLength = ratings[i];
        }
    }

    //return the star rating with the most reviews. This will be the bar graph length.
    return maxGraphLength;
}

//Determine the length of the array before the array becomes initialized, using constexpr to evaluate it during compile time.
constexpr size_t graphLength = getMaxRatingLength(ratings);

//Global array graph
std::array<char, graphLength> graph{};

void drawBarGraph(size_t length, std::array<char, graphLength>& graph);
double getAverageRating(const std::array<size_t, 5>& ratings);

int main()
{
    for(int i{0}; i < ratings.size(); i++)
    {
        std::cout << 5 - i << ": ";
        drawBarGraph(ratings[i], graph);
        std::cout << std::endl;
        graph = {};
    }

    std::cout << "Average Rating: " << std::setprecision(2) << getAverageRating(ratings);

    return 0;
}

void drawBarGraph(size_t length, std::array<char, graphLength>& graph)
{
    //Fill every index till the length determined by an element at the ratings array. Rest remain empty.
    for(size_t i{0}; i < length; ++i)
    {
        graph.at(i) = '#';
    }

    //Output the bar for that rating into the terminal
    for(const char& data : graph)
    {
        std::cout << data;
    }
}

double getAverageRating(const std::array<size_t, 5>& ratings)
{
    int totalPeople{0};
    int totalRating{0};

    //Iterate over array to add to the total ratings and total number of review made to find the average.
    for(int i{0}; i < ratings.size(); i++)
    {
        totalPeople += ratings[i];
        totalRating += (5-i)*ratings[i];
    }

    //Return as a double.
    return static_cast<double>(totalRating)/totalPeople;
}