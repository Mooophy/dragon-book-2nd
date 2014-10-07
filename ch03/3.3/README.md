3.3 Specification of Tokens
---------------------------------------------
#####Exercise 3.3.1
_Consult the language reference manuals to determine_ 
_(i)the sets if characters that form the input alphabet(excluding those that may only appear_
_in  character strings or comments)_
_(ii)the lexical form of numerical constants_
_(iii)the lexical form of identifiers, for languages:_
_(a)C  (b)C++  (c)C#  (d)Fortran  (e)Java (f)Lisp (g)SQL_
- C
 - ```[A-Za-z0-9] |  [_{}[]#()<>%:;.?*+-/^&|~!=,\"'] | {space, tab, vertical tab, feed, new-line}```, based on [wiki](http://en.wikipedia.org/wiki/C_(programming_language)#Character_set)
- C++(according to ISO C++ Standard draft n3787)
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
