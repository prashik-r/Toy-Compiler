%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
%}

%start program
%token ASSGNOP
%token LET INTEGER IN
%token SKIP IF THEN ELSE FI END WHILE DO READ WRITE
%token NUMBER IDENTIFIER
%left ':'
%left '<' '=' '>'
%left '-' '+'
%left '*' '/'
%right '^'

%%
program : LET declarations IN commands END { printf("%s\n", "Accepted"); };
declarations :
  | INTEGER IDENTIFIER { install(); } id_seq '.'
;
id_seq :
  | ',' IDENTIFIER { install(); } id_seq
;
commands :
  | commands command ';' { printf("\n"); }
;
command : SKIP
  | READ IDENTIFIER
  | WRITE exp
  | IDENTIFIER { if(!check()){ printf("[ Undeclared varible "); display(); printf("] "); } else { display(); } } ':' { push(); } exp { pop(); }
  | IF exp { printf("\n"); } THEN commands ELSE commands FI
  | WHILE exp DO commands END
;
exp : NUMBER { display(1); }
  | IDENTIFIER { if(!check()){ printf("[ Undeclared varible "); display(); printf("] "); } else { display(); } }
  | exp '<' { push(); } exp { pop(); }
  | exp '=' { push(); } exp { pop(); }
  | exp '>' { push(); } exp { pop(); }
  | exp '+' { push(); } exp { pop(); }
  | exp '-' { push(); } exp { pop(); }
  | exp '*' { push(); } exp { pop(); }
  | exp '/' { push(); } exp { pop(); }
  | exp '^' { push(); } exp { pop(); }
  | '(' exp { pop(); } ')'
;
%%

#include "lex.yy.c"
#include "stack.c"
#include "symbol_table.c"

int yyerror(char *msg) {
  printf("Invalid\n");
  exit(0);
}

int main(int argc, char const *argv[]) {
  extern FILE *yyin;
  yyin = fopen("input.txt", "r");
  yyparse();
  return 0;
}
