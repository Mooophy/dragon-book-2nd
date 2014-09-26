#include <iostream>
#include <iterator>
#include "lexer.hpp"

int main()
{
    using namespace dragon::ch2;
    using Iter = std::string::iterator;

    //! for ex2.6.2
    std::string input{"< <= == != >= > .33"};
    Lexer<Iter> lex{input.begin(), input.end()};

    while(lex.not_end())
        std::cout << lex.scan()->tag << std::endl;
    std::cout << "lines = " << lex.lines() << std::endl;

    std::cout << "exit normally\n";
    return 0;
}

