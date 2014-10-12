//! @author Yue Wang
//! @date   12 Oct 2014
//! @note   this code is implmented to test the exercise 3.3.2
//! @attention  -std=c++11 flag is needed to compile :
//!
//!                 clang++ -std=c++11 -Wall -ex332.cpp -o ex332
//! 
//!             tested on clang++ 3.5
//!

#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <assert.h>

/**
 * @brief The Ex332 class
 *
 * storing all patterns in ex 3.3.2
 */
class Ex332
{
public:
    Ex332():
        patterns
    {
        "a(a|b)*a",
        "(a?b*)*",
        "(a|b)*a(a|b)(a|b)",
        "a*ba*ba*ba*",
        "(aa|bb)*((ab|ba)(aa|bb)*(ab|ba)(aa|bb)*)*"
    },
        rg{5}
    {
        for(unsigned index = 0; index != patterns.size(); ++index)
            rg[index] = patterns[index];
    }

    const std::string& pattern(std::size_t sub) const
    {
        return patterns[sub - 1];
    }

    bool operator ()(std::size_t sub, const std::string& input)const
    {
        return std::regex_match(input, rg[sub - 1]);
    }

private:
    std::vector<std::string> patterns;
    std::vector<std::regex> rg;
};

int main()
{
    std::cout << "Enter 1-5 for subexercise:\n";
    std::string chosen;
    for(std::regex re{"[1-5]"}; std::cin >> chosen   &&  !std::regex_match(chosen, re); /* */)
            std::cout << "Pls enter 1-5\n";

    Ex332 exercise;
    unsigned sub = std::stoi(chosen);
    std::cout << "subexercise " << chosen <<" pattern : "
              << exercise.pattern(sub) << "\nEnter your try:\n";

    for(std::string tries; std::cin >> tries;)
        std::cout <<    (exercise(sub,tries)?    "match!\n"  :   "no match!\n")
                  <<    "more try:\n";
}

