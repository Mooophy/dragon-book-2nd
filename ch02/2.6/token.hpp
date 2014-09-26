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
    static const int END    =   999;    //as end of input
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
#endif // TOKEN_HPP
