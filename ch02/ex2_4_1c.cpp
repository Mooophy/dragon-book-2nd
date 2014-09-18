#include <iostream>
#include <functional>


namespace dragon {namespace ch2 {

template<typename Iter>
bool parse_241c(Iter first, Iter last)
{
    bool ret = true;
    using Lambda = std::function<Iter(Iter)>;
    Lambda parse = [&parse, &ret, last](Iter curr)->Iter
    {
        if(*curr == '0')
        {
            parse()

//            if (*(curr + 1) == '1')
//                return curr + 2;
//            else
//                return parse(curr + 1);
        }
        else
        {
            ret = false;
            return last + 1;
        }
    };

    parse(first);

    return ret;
}

}}//namespace


int main()
{
    std::cout << "enter statements, pls follow : S -> \n";

    for(std::string buff; std::cin >> buff; /* */)
    {
        bool is_legal = dragon::ch2::parse_241c(buff.begin(),buff.end());
        std::cout << "@parser ex2.4.1.c --> "
                  << (is_legal?     "legal\n"     :   "syntax error\n");
    }

    return 0;
}
