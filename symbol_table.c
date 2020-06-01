struct Node {
  char *name;
  struct Node *next;
};
typedef struct Node Node;
Node *table_head = NULL;

int check() {
  Node *tmp = table_head;
  while(tmp != NULL) {
    if(strcmp(tmp->name, yytext) == 0) {
      return 1;
    }
    tmp = tmp->next;
  }
  return 0;
}

Node *create(char *id) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->name = (char *)malloc(strlen(id) + 1);
  strcpy(node->name, id);
  return node;
}

int install() {
  if(table_head == NULL) {
    table_head = create(yytext);
  } else {
    if(check()) {
      printf("The identifier '%s' is already declared\n", yytext);
    } else {
      Node *tmp = create(yytext);
      tmp->next = table_head;
      table_head = tmp;
    }
  }
  return 0;
}
