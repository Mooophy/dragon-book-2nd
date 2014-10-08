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
 - `Identifier: IdentifierChars but not a Keyword or BooleanLiteral or NullLiteral` check 3.8 for the rest
 - 
