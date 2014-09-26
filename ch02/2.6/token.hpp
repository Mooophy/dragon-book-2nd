//! @file   token.hpp
//!
//! @author Yue Wang
//! @date   26 Sep 2014
//!

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <memory>

namespace dragon {namespace ch2 {
namespace Tag
{
    static const int NUM    =   256;
    static const int ID     =   257;
    static const int TRUE   =   258;
    static const int FALSE  =   259;

    static const int LESS   =   260;
    static const int LESSEQ =   261;
    static const int EQ     =   262;
    static const int NOTEQ  =   263;
    static const int GREEQ  =   264;
    static const int GRE    =   265;
    static const int REAL   =   270;

    static const int END    =   999;    //as end of input
}

struct Token
{
   const int tag;
};

struct Num : public Token
{
    explicit Num(int val):
        Token{Tag::NUM}, value{val}
    {}

    const int value;
};

struct Word : public Token
{
    Word(int tag, const std::string& lx):
        Token{tag},lexeme{lx}
    {}

    const std::string lexeme;
};

struct Op : public Token
{
    explicit Op(int tag):
        Token{tag}
    {}
};

struct Real : public Token
{
    explicit Real(float val):
        Token{Tag::REAL}, value{val}
    {}

    const float value;
};

using TokenSptr = std::shared_ptr<Token>;

}}//namespace
#endif // TOKEN_HPP
