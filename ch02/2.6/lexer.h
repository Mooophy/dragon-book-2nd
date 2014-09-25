#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <unordered_map>

namespace dragon {namespace ch2 {

class Lexer
{
public:
    using HashTable =   std::unordered_map<std::string, TokenSptr>;

    //! @Ctor
    Lexer():
        curr_line{1},
        peek{' '},
        words{}
    {
        reserve(Word{Tag::TRUE, "true"});
        reserve(Word{Tag::FALSE, "false"});
    }

    TokenSptr scan();

private:
    int curr_line;
    char peek;
    HashTable words;

    void reserve(const Word& w)
    {
        TokenSptr t = std::make_shared<Word>(w);
        words.insert({w.lexeme, t});
    }
};

}}//namespace

#endif // LEXER_H
