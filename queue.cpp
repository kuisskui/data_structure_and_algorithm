#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct queue {
  node *front;
  node *rear;
  int size;
} queue;

void enqueue(queue *q, int v) {
  //////////////////////////////
  //////////////////////////////
}

int is_queue_empty(queue *q) {
  //////////////////////////////
  ///////// return ??? /////////
}

int dequeue(queue *q) {
  //////////////////////////////
  ///////// return ??? /////////
}

int main() {
  queue Q = {NULL, NULL, 0};
  int op, v;
  while (true) {
    printf("Menu : ");
    scanf("%d", &op);
    if (op == 0) {
      scanf("%d", &v);
      enqueue(&Q, v);
    } else if (op == 1) {
      if (is_queue_empty(&Q) == 1)
        printf("Queue is already empty!!!\n");
      else
        printf("%d\n", dequeue(&Q));
    } else {
      printf("END CODE\n");
      break;
    }
  }
  return 0;
}