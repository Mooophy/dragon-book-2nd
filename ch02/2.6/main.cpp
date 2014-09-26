#include <iostream>
#include <iterator>
#include "lexer.hpp"

int main()
{
    using namespace dragon::ch2;
    using Iter = std::string::iterator;

    std::string input{"s*-111"};
    Lexer<Iter> lex{input.begin(), input.end()};

    while(lex.not_end())
        std::cout << lex.scan()->tag << std::endl;

    std::cout << "exit normally\n";
    return 0;
}

