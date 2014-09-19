//!
//! @author     Yue Wang
//! @date       18 Sep 2014
//!
//! ex2.4.1.a
//! parse
//!         S -> '+' S S | '-' S S | 'a'
//!
#include <iostream>
#include <string>
#include <functional>

namespace dragon{ namespace ch2{

/**
 * @brief parse_241a
 * @param first
 * @param last
 * @return  true if legal, false otherwise.
 *
 * @complexity  O(n)
 */
template<typename Iter>
inline bool parse_241a(Iter first, Iter last)
{
    bool is_legal = true;

    //! define lambda s for real work
    std::function<Iter(Iter)> s = [&](Iter curr) -> Iter
    {
        if(*curr == 'a')
            return curr + 1;
        else if(*curr == '+'   ||  *curr == '-')
            return s(s(curr + 1));
        else
        {
            is_legal = false;
            return last;
        }
    };

    //! @note   since lambda s cover all the possibilites, the iterator
    //!         returned for a legal input must point to last.
    return is_legal  &&  s(first) == last;
}
}}//namespace

int main()
{
    std::cout << "pls enter, following : S -> '+' S S | '-' S S | 'a'\n";

    for(std::string buff; std::cin >> buff; /* */)
    {
        bool is_legal = dragon::ch2::parse_241a(buff.begin(),buff.end());
        std::cout << "@parser ex2.4.1.a --> "
                  << (is_legal?     "legal\n"     :   "syntax error\n");
    }

    return 0;
}

