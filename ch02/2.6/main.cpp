//! @file   main.cpp
//!
//! @author Yue Wang
//! @date   26 Sep 2014
//!
//! @note   this file tests lexer implemented for ex2.6.1~3.
//! @output:
//0.2
//5.2
//2
//if
//else
//class
//2
//6
//9
//lines = 5
//num of tokens = 17

//exit normally

#include <iostream>
#include <iterator>
#include <vector>
#include "lexer.hpp"

int main()
{
    using namespace dragon::ch2;
    using Iter = std::string::iterator;

    //! for ex2.6.1 handle comments
    std::string input{"\\\\comment1\n"};
    input += "\\*comment2\n\n\n*\\";

    //! for ex2.6.2 handle operators
    input += "< <= == != >= >";

    //! for ex2.6.3 handle real numbers
    input += ".2 5.2 2.0";

    //! for identifier
    input += "if else class ";

    //! for num like 2 6 9
    input += "2 6 9";
    Lexer<Iter> lex{input.begin(), input.end()};

    std::vector<TokenSptr> v{};
    while(lex.not_end())
    {
        auto token = lex.scan();

        if(token->tag   ==  Tag::REAL)
            if(auto r   =   std::dynamic_pointer_cast<Real>(token))
                std::cout << r->value   << std::endl;

        if(token->tag   ==  Tag::ID)
            if(auto id  =   std::dynamic_pointer_cast<Word>(token))
                std::cout << id->lexeme << std::endl;

        if(token->tag   ==  Tag::NUM)
            if(auto num =   std::dynamic_pointer_cast<Num>(token))
                std::cout << num->value << std::endl;

        v.push_back(token);
    }
    std::cout << "lines = " << lex.lines() << std::endl;
    std::cout << "num of tokens = " << v.size();

    std::cout << "\n\nexit normally\n";
    return 0;
}


