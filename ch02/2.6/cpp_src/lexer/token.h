#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <memory>

namespace dragon {namespace ch2 {

enum class Tag
{
    NUM = 256, ID = 257, TRUE = 258, FALSE = 259
};

struct Token
{
   const Tag tag;
};

struct Num : public Token
{
    Num(int val):
        Token{Tag::NUM}, value{val}
    {}

    const int value;
};

struct Word : public Token
{
    Word(Tag t, const std::string& lx):
        Token{t},lexeme{lx}
    {}

    const std::string lexeme;
};

using TokenSptr = std::shared_ptr<Token>;

}}//namespace
#endif // TOKEN_H
