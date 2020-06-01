char stack[1000];
int top = 0;
int push() {
  stack[top++] = yytext[0];
  return 0;
}
int pop() {
  printf("%c ", stack[--top]);
  return 0;
}
int display() {
  printf("%s ", yytext);
  return 0;
}
