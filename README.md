# Toy Compiler

The project presents a simple toy compiler to perform various phases of the compilation process. The tools used to develop the compiler are [Flex](https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/) and [Yacc](https://www.geeksforgeeks.org/introduction-to-yacc/).

## Project Description 

Phases of the compiler implemented are :
 1) Lexical Analysis
 2) Syntax Analysis
 3) Semantic Analysis
 4) Intermediate Code Generation 
 5) Code Optimization

The lexical analysis phase is implemented by the lex file compiler.l.c. It takes the source program as input from the input.txt file and convert the program into stream of tokens.The syntax and semantic analysis part is handled by the yacc file compiler.y.c through the grammar specified and actions corresponding to specifies rules which are present in the yacc file. Variable declaration is checked through the symbol table implemented by symbol_table.c . The intermediate code form used is postfix notation which is implemented using stack, the stack is being implemented by the stack.c file.    

## Grammer 

The grammer used to develop the compiler :
```
program ::= LET [ declarations ] IN commands END
declarations ::= INTEGER IDENTIFIER id_seq .
id seq ::= , IDENTIFIER id_seq
commands ::= commands command ;
command ::= SKIP ;
| READ IDENTIFIER ;
| IF expression THEN commands ELSE commands FI ;
| WHILE expression DO commands END ;
| IDENTIFIER : expression ;
| WRITE expression ;
expression ::= NUMBER
| IDENTIFIER
| ’(’ expression ’)’
| expression + expression
| expression − expression
| expression ∗ expression
| expression / expression
| expression ˆ expression
| expression = expression
| expression < expression
| expression > expression
``` 
## Running The Code

```bash
lex compiler.l
``` 
```bash
yacc compiler.y -d
``` 
```bash
gcc y.tab.c -w
``` 
```bash
./a.out
``` 
