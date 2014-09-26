2.6 Lexical Analysis
--------------------------

###Contents
- lexer.hpp
 - class Lexer
- token.hpp
 - token classes hierarchy
- main.cpp
 - for testing
- java/
 - storing sample codes in java as on the textbook

###MEMO
- Notes for design
 - Generics iterator was chosen for `peek` rather`char` as on textbook, which improves flexibility.
 - `Tag::END` was added to end input.(but seems it is not quite useful) 
- Notes for C++
 - `std::dynamic_pointer_cast<>` can be used to cast smart pointers, so that the derived class object's data member can be accessed. Check `main.cpp` for more.
 - `virtual destructor` must be implemented before using `std::dynamic_pointer_cast<>`.
- Exercises 
 - `2.6.1`,`2.6.2`,`2.6.3` have been implemented in the C++ codes above.
- To compile and run :
 - `make -k` 
 - `./dragon26`
- Output is supposed to be something like:
```
0.2
5.2
2
if
else
class
2
6
9
lines = 5
num of tokens = 17

exit normally
```
#### Try it.
