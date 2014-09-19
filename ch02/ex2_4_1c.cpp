//!
//! @author     Yue Wang
//! @date       19 Sep 2014
//!
//! ex2.4.1.c
//! parse
//!         S -> 0S1 | 01
//!
//! sample inputs : 01  0011    000111  00001111, etc
//!

#include <iostream>
#include <string>
#include <functional>

namespace dragon {namespace ch2 {

/**
 * @brief parse_241c
 * @param first
 * @param last
 * @return  true if legal, false otherwise.
 *
 * @complexity  O(n)
 */
template<typename Iter>
bool parse_241c(Iter first, Iter last)
{
    bool is_legal = true;

    //! define lambda s for real work
    std::function<Iter(Iter)> s = [&](Iter curr) -> Iter
    {
        if(*curr == '0'  && *(curr + 1) =='1')
            return curr + 2;
        else if(*curr == '0')
        {
            Iter tail = s(curr + 1);
            is_legal =  *tail == '1';
            return tail + 1;
        }
        else
        {
            is_legal = false;
            return last;
        }
    };

    //! call lambda and return
    s(first);
    return is_legal;
}
}}//namespace


int main()
{
    std::cout << "pls enter, using grammar : S -> 0S1 | 01\n";

    for(std::string buff; std::cin >> buff; /* */)
    {
        bool is_legal = dragon::ch2::parse_241c(buff.begin(),buff.end());
        std::cout << "@parser ex2.4.1.c --> "
                  << (is_legal?     "legal\n"     :   "syntax error\n");
    }

    return 0;
}
