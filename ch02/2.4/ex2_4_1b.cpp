//!
//! @author     Yue Wang
//! @date       20 Sep 2014
//!
//! ex2.4.1.b
//! parse
//!         S -> S(S)S|empty
//!
//! legal inputs :
//!                 ()
//!                 (())
//!                 ()()()()
//!                 ( () () )
//!                 etc
//!

#include <iostream>
#include <functional>


namespace dragon{ namespace ch2{

template<typename Iter>
bool parse_241b(Iter first, Iter last)
{
    bool is_legal = true;
    //! define lambda s for real work
    std::function<Iter(Iter)> s = [&](Iter curr) -> Iter
    {
        if(last - curr < 2)
            is_legal = false;

        if(*curr == '('     &&  *(curr + 1) == ')')
            return curr + 2;
        else if(*curr == '(')
        {
            Iter tail = s(curr + 1);
            is_legal = *tail == ')';
            return tail + 1;
        }
        else
            is_legal = false;

        return last;
    };

    //! use lambda s
    for(auto curr = first; curr != last; curr = s(curr));

    return is_legal;
}

}}//namespace

int main()
{
    std::cout << "pls enter, using grammar : S -> \n";
    
    for(std::string buff; std::cin >> buff; /* */)
    {
        bool is_legal = dragon::ch2::parse_241b(buff.begin(),buff.end());
        std::cout << "@parser ex2.4.1.b --> "
                  << (is_legal?     "legal\n"     :   "syntax error\n");
    }

    return 0;
}
