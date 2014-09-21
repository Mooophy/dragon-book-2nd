#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>

namespace dragon {namespace ch2 {

class Postfix
{
public:
    using Iter = std::istream_iterator<char>;
    Postfix():
        curr{std::cin}
    {}

    void operator()()
    {
        term();
        for(++curr; *curr == '+' || *curr == '-' ;  ++curr)
        {
            auto optr = *curr++;
            term();
            std::cout << optr;
        }
    }

private:
    Iter curr;

    void term()
    {
        if(std::isdigit(*curr))
            std::cout << *curr;
        else
            throw std::runtime_error{"syntax error"};
    }
};
}}//namespace



#endif // POSTFIX_HPP
