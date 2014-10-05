2.8 Intermediate Code Generation
--------------------------------
- ex2.8.1
```
For-statements in C and Java have the form:

for ( exprl ; expr2 ; expr3 ) stmt

The first expression is executed before the loop; it is typically used for initializing
the loop index. The second expression is a test made before each iteration of the loop;
the loop is exited if the expression becomes 0. The loop itself can be thought of as the
statement {stmt expr3 ; }. The third expression is executed at the end of each iteration;
it is typically used to increment the loop index. The meaning of the for-statement is
similar to

expr1 ; while ( expr2 ) {stmt expr3 ; }

Define a class For for for-statements, similar to class If in Fig. 2.43.
```
