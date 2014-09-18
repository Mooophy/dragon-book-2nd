#include <iostream>
#include <string>

namespace dragon{ namespace ch2{

template<typename Iter>
void parse(Iter& curr, Iter last, bool& ret)
{
    if(*curr == 'a')
        ++curr;
    else if(*curr == '+'   ||  *curr == '-')
    {
        ++curr;
        parse(curr,last, ret);
        parse(curr,last, ret);
    }
    else
        ret = false;
}

template<typename Iter>
inline bool
parse_241a(Iter first, Iter last)
{
    bool ret = true;
    Iter curr= first;
    while(1)
    {
        parse(curr, last, ret);

        if(curr == last)    break;
        else                ++curr;
    }

    return ret;
}
}}//namespace


int main()
{
    std::cout << "enter your statement, pls follow : S -> '+' S S | '-' S S | 'a'\n";

    for(std::string buff; std::cin >> buff; /* */)
    {
        bool is_legal = dragon::ch2::parse_241a(buff.begin(),buff.end());

        std::cout << "@parser ex2.4.1.a --> "
                  << (is_legal?     "legal\n"     :   "syntax error\n");
    }
    return 0;
}

