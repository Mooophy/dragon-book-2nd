#ifndef TOKEN_H
#define TOKEN_H

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

    int value;
};

}}//namespace
#endif // TOKEN_H
