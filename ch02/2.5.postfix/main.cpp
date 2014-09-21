#include <postfix.hpp>

int main()
{
    using Iter  =    std::istream_iterator<char>;

    dragon::ch2::Postfix<Iter> parse{{std::cin}};
    parse();

    return 0;
}
