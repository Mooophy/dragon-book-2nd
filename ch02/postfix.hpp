#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>

namespace dragon {namespace ch2 {

class Postfix
{
public:
    using Iter = std::istreambuf_iterator<char>;

    Postfix():
        curr{std::cin},end{}
    {}

    void expr()
    {
        term();

    }

private:
    Iter curr;
    Iter end;

    void term()
    {
        if(std::isdigit(*curr))
        {
            std::cout << *curr;
            next();
        }
        else
            throw std::runtime_error{"syntax error\n"};
    }

    void match(char t)
    {
        if(t == *curr)
            next();
        else
            throw std::runtime_error{"syntax error\n"};
    }

    void next()
    {
        ++curr;
        return *this;
    }
};
}}//namespace



#endif // POSTFIX_HPP
