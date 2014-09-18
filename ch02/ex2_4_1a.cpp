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

namespace dragon{ namespace ch2{

/**
 * @brief parse
 * @param curr      i.e. lookahead
 * @param ret       bool to store whether the syntax legal
 *
 * perform the real work
 */
template<typename Iter>
void parse(Iter& curr, bool& ret)
{
    if(*curr == 'a')
        ++curr;
    else if(*curr == '+'   ||  *curr == '-')
    {
        ++curr;
        parse(curr, ret);
        parse(curr, ret);
    }
    else
        ret = false;
}

/**
 * @brief parse_241a
 * @param first
 * @param last
 * @return  true if legal, false otherwise.
 */
template<typename Iter>
inline bool parse_241a(Iter first, Iter last)
{
    bool ret = true;
    Iter curr= first;
    while(1)
    {
        parse(curr, ret);

        if(curr == last)    break;
        else                ++curr;
    }

    return ret;
}
}}//namespace


int main()
{
    std::cout << "enter statements, pls follow : S -> '+' S S | '-' S S | 'a'\n";
    for(std::string buff; std::cin >> buff; /* */)
    {
        bool is_legal = dragon::ch2::parse_241a(buff.begin(),buff.end());
        std::cout << "@parser ex2.4.1.a --> "
                  << (is_legal?     "legal\n"     :   "syntax error\n");
    }
    return 0;
}

