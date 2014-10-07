3.1 The Role of the Lexical Analyzer
-----------------------------------------------
#####Exercise 3.1.1

_Divide the following C++ program:_
```cpp
float limitedSquare(float x)
{
    return (x <= -10.0 || x >= 10.0)?   100     :   x * x;
}
```
_into appropriate lexemes,using Section 3.1.2 as a guide._
_Which lexemes should get associated lexical value?_
_What should those value be?_

- Solution, using Example 3.2:
```
<id,pointer to symbol-table entry for limitedSquare>
<x,pointer to symbol-table entry for x>
```
