#include <iostream>
#include <iterator>
#include "lexer.hpp"

int main()
{
    using namespace dragon::ch2;
    using Iter = std::string::iterator;

    //! for ex2.6.3
    std::string input{"522.34*"};
    Lexer<Iter> lex{input.begin(), input.end()};

    while(lex.not_end())
    {
        auto token = lex.scan();
        if(token->tag   ==  Tag::REAL)
            if(auto r = std::dynamic_pointer_cast<Real>(token))
                std::cout << r->value << std::endl;
    }
    std::cout << "lines = " << lex.lines() << std::endl;

    std::cout << "exit normally\n";
    return 0;
}

