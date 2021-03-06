3.3 Specification of Tokens
---------------------------------------------
#####Exercise 3.3.1
_Consult the language reference manuals to determine_ 
_(i)the sets if characters that form the input alphabet(excluding those that may only appear_
_in  character strings or comments)_
_(ii)the lexical form of numerical constants_
_(iii)the lexical form of identifiers, for languages:_
_(a)C  (b)C++  (c)C#  (d)Fortran  (e)Java (f)Lisp (g)SQL_
- C (according to ISO C Standard draft `n1256`, Sep 2007)
 - same as C++ , based on [wiki](http://en.wikipedia.org/wiki/C_(programming_language)#Character_set)
 - same as C++
 - same as C++
- C++ (according to ISO C++ Standard draft `n3787`, Oct 2013)
 - ```[A-Za-z0-9] |  [_{}[]#()<>%:;.?*+-/^&|~!=,\"'] | {space, tab, vertical tab, feed, new-line}```, Based on section 2.3, C++ Standard.
 - For instance : `integer-literal: decimal-literal integer-suffixopt` check C++ Standard section 2.14 for the rest, which are too tedious to paste here.
 - Copied from section 2.11, C++ standard:
```
identifier:
        identifier-nondigit
        identifier identifier-nondigit
        identifier digit
identifier-nondigit:
        nondigit
        universal-character-name
        other implementation-defined characters
nondigit: one of
        a b c d e f g h i j k l m
        n o p q r s t u v w x y z
        A B C D E F G H I J K L M
        N O P Q R S T U V W X Y Z _
digit: one of
        0 1 2 3 4 5 6 7 8 9
```
- C# (according to `C# Language Specification Version 5.0, 2012`)
 - `A Unicode character escape sequence` check section 2.4.1 for more.
 - check section 2.4.4 for numerical constands.
 - check section 2.4.2 for identifiers.
- Fortran95 (according to ISO Fortran Standard draft n1122, Aug 2013)
 - `The processor character set is processor dependent.The letters, digits, underscore, and special characters make up the Fortran character set.` check section 3.1 for detail.
 - check 3.2.2 for detail
 - check 3.3 for detail
- Java (according to `The Java® Language Specification SE 7 Edition, Feb 2013`)
 - `UnicodeInputCharacter but not CR or LF ` check section 3 for detail.
 - check 3.10 for detail.
 - something like :  `Identifier: IdentifierChars but not a Keyword or BooleanLiteral or NullLiteral` check 3.8 for the rest
- Lisp (using Scheme dialect as the example)(according to `Revised5 Report on the Algorithmic Language Scheme, Feb 1998`)
 - From section 2.1 : `The precise rules for form-ing identiers vary among implementations of Scheme, but in all implementations a sequence of letters, digits, and \ex-tended alphabetic characters" that begins with a character that cannot begin a number is an identier`
 - check 7.1.1.
 - check 7.1.1.
- Sql (according to `Second Informal Review Draft ISO/IEC 9075:1992 Database Language SQL, July 1992`)
 - something like `<SQL terminal character> ::=  <SQL language character> | <SQL embedded language character>`,check section 5.1 for the rest.
 - check 5.3 for detail.
 - `<identifier> ::= [ <introducer><character set specification> ] <actual identifier>`, check section 5.4 for the rest parts. 

#####Exercise 3.3.2
Describe the languages denoted by the following regular expressions:
```ecma
a) a(a|b)*a
b) ((ε|a)b*)*
c) (a|b)*a(a|b)(a|b)
d) a*ba*ba*ba*
!!e) (aa|bb)*((ab|ba)(aa|bb)*(ab|ba)(aa|bb)*)*
```
- Solution:
 - a) something like : `aa`,`aaa`,`aba`,`aaaabbbba`,`aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa`
 - b) something like : `b`,`ab`,`abbabb`
 - c) something like :  `aaaaaaaa`,`aaaaaaaaabb`,`aaaaaaaaaaaaaab`
 - d) something like :  `bbb`, `baaaaabaaaaaaba`,`abbb`, `abababa`
 - e) something like :  `aa`,`bb`,`abab`,`abba`
 - note) code : ex332.cpp in this folder can be used for testing this exercise.

#####Exercise 3.3.3
In a string of length n , how many of the following are there?
- Prefixes.
- Suffixes.
- Proper prefixes.
- ! Substrings.
- ! Subsequences.
Solution
- n + 1
- n + 1
- n - 1
- n(n+1)/2
- Σ(i= 0 to n) C(n, i)

#####Exercise 3.3.4
Most languages are case sensitive, so keywords can be written only one way, and the regular expressions describing their lexeme is very simple. However, some languages, like SQL, are case insensitive, so a keyword can be written either in lowercase or in uppercase, or in any mixture of cases. Thus, the SQL keyword SELECT can also be written select, Select, or sElEcT, for instance. Show how to write a regular expression for a keyword in a case­ insensitive language. Illustrate the idea by writing the expression for "select" in SQL.

Solution : `[sS][eE][lL][eE][cC][tT]`

#####Exercise 3.3.5
！Write regular definitions for the following languages:

- All strings of lowercase letters that contain the five vowels in order.
- All strings of lowercase letters in which the letters are in ascending lexicographic order.
- Comments, consisting of a string surrounded by /* and */, without an intervening */, unless it is inside double-quotes (")
- All strings of digits with no repeated digits. Hint: Try this problem first with a few digits, such as {O, 1, 2}.!!
- All strings of digits with at most one repeated digit.!!
- All strings of a's and b's with an even number of a's and an odd number of b's.!!
- The set of Chess moves,in the informal notation,such as p-k4 or kbp*qn.
- All strings of a's and b's that do not contain the substring abb.!!
- All strings of a's and b's that do not contain the subsequence abb.

Solution : 
- `(rest|a)*a(rest|a)*(rest|e)*e(rest|e)*(rest|i)*i(rest|i)*(rest|o)*o(rest|o)*(rest|u)*u(rest|u)*`, `rest->[b-d]|[f-h]|[j-n]|[p-t][v-z]`
- `a*b*c*d*...x*y*z*`
- `/*([^*"]|".*"|*[^/])**/`(no escape), use the C++ code below for testing:
```cpp
#include <boost/regex.hpp>
#include <iostream>
int main ()
{
    std::string pattern {"/\\*([^\\*\"]|\".*\"|\\*[^/])*\\*/"};
    //!  with escapes     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^
    boost::regex e{pattern};
    std::string str{"/*sss\"*/\"s*/"};
    std::cout << boost::regex_match(str,e);
    return 0;
}

```
