#include <iostream>
#include "token.h"
#include "lexer.h"

int main()
{
    using namespace dragon::ch2;

    Lexer lex{};
    std::cout << lex.scan()->tag;

    return 0;
}

