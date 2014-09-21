//!
//! @author     Yue Wang
//!
//! @date       22 Sep 2014
//! @file       postfix.hpp
//!

#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>

namespace dragon {namespace ch2 {

/**
 * @brief      Postfix C++ version
 *
 * @note       Based on the java implementation in section 2.5, this one
 *             has been optimized. For readability pls refer to the java
 *             version.
 *
 * @complexity  O(n)
 */
template<typename Iter>
class Postfix
{
public:
    Postfix(Iter cr):
        curr{cr}
    {}

    /**
     * @brief operator ()
     *
     * i.e. expr() in the java version
     */
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
