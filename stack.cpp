#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct stack {
  node *top;
  int size;
} stack;

void push(stack *s, int v) {
  node *new_node = new node();
  new_node->value = v;

  if (s->top){
    new_node->next = s->top;
    s->top = new_node;
  } else{
    s->top = new_node;
  }
  s->size++;
}

int is_stack_empty(stack *s) {
  if (s->size){
    return -1;
  }
}

int pop(stack *s) {
  int value = s->top->value;
  s->top = s->top->next;
  s->size--;
  return value;
}

int main() {
  stack top = {NULL, 0};
  int op, v;
  while (true) {
    printf("Menu : ");
    scanf("%d", &op);
    if (op == 0) {
      scanf("%d", &v);
      push(&top, v);
    } else if (op == 1) {
      if (is_stack_empty(&top) == 1)
        printf("Stack is already empty!!!\n");
      else
        printf("%d\n", pop(&top));
    } else {
      printf("END CODE\n");
      break;
    }
  }
  return 0;
}