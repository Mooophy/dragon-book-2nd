#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>

namespace dragon {namespace ch2 {

template<typename Iter>
class Postfix
{
public:
    using ValueType =   typename std::iterator_traits<Iter>::value_type;

    Postfix(Iter first, Iter last):
        curr{first}, end{last}
    {}

    void operator()()
    {
        term();
        while(curr != end   &&  (*curr == '+'   ||  *curr == '-'))
        {
            auto optr = *curr;
            ++curr;
            term();
            std::cout << optr;
        }
    }

private:
    Iter curr;
    Iter end;

    void term()
    {
        if(std::isdigit(*curr))
        {
            std::cout << *curr;
            ++curr;
        }
        else
            throw std::runtime_error{"syntax error : digit expected\n"};
    }

    void match(ValueType t)
    {
        if(t == *curr)  ++curr;
        else            throw std::runtime_error{"syntax error : can't match\n"};
    }
};
}}//namespace



#endif // POSTFIX_HPP
