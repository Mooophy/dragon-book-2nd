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
#####Exercise 3.1.2
_Tagged languages like HTML or XML are different from con­ ventional programming languages_ 
_that the punctuation (tags) are either very numerous (as in HTML) or a user-definable set_
_(as in XML) . Further, tags can often have parameters. Suggest how to divide the following_
_HTML document:_
```html
Here is a photo of <b>my house</b>:
<p><img src="house.gif"><br>
see <a href="morePix.html">More Picture</a> if you liked that one.</p>
```
_into appropriate lexemes. Which lexemes should get associated lexical values, and what should_
_those values be?_
- Solution :
```
<literal, "Here is a photo of "><b_start><literal, "my house"><b_end><literal, ":">
<p_start><img_start><img, pointer to symbol table entry><img->src,""house.gif""><img_end><br>
<literal, "See "><a_start><href, "morePix.html"><literal, "More Picture"><a_end>
<literal, " if you liked that one."><p_end>



```
