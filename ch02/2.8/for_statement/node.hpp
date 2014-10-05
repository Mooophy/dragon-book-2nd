//! @author Yue Wang
//! @date   6   Oct 2014

#ifndef NODE_HPP
#define NODE_HPP

#include <stdexcept>
#include <string>

namespace dragon {namespace ch2 {

/**
 * @brief The Node class
 *
 * based on the java version that can be found at appendix A.5
 */
class Node
{
public:
    explicit Node(int line):
        lexline{line}
    {}

    void error(const std::string& msg)
    {
        throw std::runtime_error{"near line " + std::to_string(lexline) + " : " + msg};
    }

    int new_label()
    {
        return ++labels;
    }

    void emit_label(int i) const
    {
        std::cout << "L" << i << " : ";
    }

    void emit(const std::string& msg)const
    {
        std::cout << "\t" << msg;
    }


    static int labels;
private:
    int lexline;
};


}}//namespace
#endif // NODE_HPP
