3.1 The Role of the Lexical Analyzer
-----------------------------------------------
#####Exercise 3.1.1
```
Divide the following C++ program:

float limitedSquare(float x)
{
    return (x <= -10.0 || x >= 10.0)?   100     :   x * x;
}

into appropriate lexemes,using Section 3.1.2 as a guide.
Which lexemes should get associated lexical value?
What should those value be?
```
- Solution, using Example 3.2:
```
<id,pointer to symbol-table entry for limitedSquare>
<x,pointer to symbol-table entry for x>
```
