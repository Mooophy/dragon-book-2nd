#include <iostream>
#include "token.h"

int main()
{
    using namespace dragon::ch2;

    Token t{Tag::NUM};
    Num n{2};
    Word w{Tag::ID, "if"};

    return 0;
}

