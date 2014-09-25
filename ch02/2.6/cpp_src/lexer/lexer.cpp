#include "lexer.h"
#include <iostream>

namespace dragon {namespace ch2 {

TokenSptr Lexer::scan()
{
    for(; ; std::cin >> peek)
    {
        if( peek == ' ' || peek == '\t')
            continue;
        else if (peek == '\n')
            ++curr_line;
        else break;
    }

    if(std::isdigit(peek))
    {
        int v = 0;
        do{
            v = v*10 + peek - 48;
            std::cin >> peek;
        }while(std::isdigit(peek));

        return std::make_shared<Num>(v);
    }

    if(std::isalpha(peek))
    {
        std::string key{};
        do{
            key.push_back(peek);
            std::cin >> peek;
        }while(std::isalpha(peek)   ||  std::isdigit(peek));

        auto w = words.find(key);
        if(w != words.end())    return w->second;
        auto ret = std::make_shared<Word>(Tag::ID, key);
        words.insert({key, ret});
        return ret;
    }
    TokenSptr token = std::make_shared<Token>(Token{peek});
    peek = ' ';

    return  token;
}

}}//namespace


