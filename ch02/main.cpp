#include <postfix.hpp>

int main()
{
    using Iter  =   std::istream_iterator<char>;
    auto first  =   Iter{std::cin};
    auto last   =   Iter{};

    dragon::ch2::Postfix<Iter> parse{first, last};

    parse();

    return 0;
}
