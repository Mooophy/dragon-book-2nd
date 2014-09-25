#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <memory>

namespace dragon {namespace ch2 {
namespace Tag
{
    static const int NUM    =   256;
    static const int ID     =   257;
    static const int TRUE   =   258;
    static const int FALSE  =   259;
}

struct Token
{
   const int tag;
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
    Word(int t, const std::string& lx):
        Token{t},lexeme{lx}
    {}

    const std::string lexeme;
};

using TokenSptr = std::shared_ptr<Token>;

}}//namespace
#endif // TOKEN_H
