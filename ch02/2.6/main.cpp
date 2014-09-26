#include <iostream>
#include <iterator>
#include "lexer.hpp"

int main()
{
    using namespace dragon::ch2;
    using Iter = std::string::iterator;

    std::string input{" s \t*\t 2"};
    Lexer<Iter> lex{input.begin(), input.end()};

    std::cout << lex.scan()->tag << std::endl;
    return 0;
}

