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
  //////////////////////////////
  //////////////////////////////
}

int is_stack_empty(stack *s) {
  //////////////////////////////
  ///////// return ??? /////////
}

int pop(stack *s) {
  //////////////////////////////
  ///////// return ??? /////////
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