DIGIT [0-9]
ID [a-z][a-z0-9]*

%%
{DIGIT}+ {
  return NUMBER;
}
let {
  return LET;
}
int {
  return INTEGER;
}
in {
  return IN;
}
skip {
  return SKIP;
}
if {
  return IF;
}
then {
  return THEN;
}
else {
  return ELSE;
}
fi {
  return FI;
}
end {
  return END;
}
while {
  return WHILE;
}
do {
  return DO;
}
read {
  return READ;
}
write {
  return WRITE;
}
{ID} {
  return IDENTIFIER;
}
[ \t\n]+ {
  // ignore
}
. {
  return(yytext[0]);
}
%%

int yywrap() {
  return 1;
}
