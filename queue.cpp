#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node
{
  int value;
  struct node *next;
} node;

typedef struct queue
{
  node *front;
  node *rear;
  int size;
} queue;

void enqueue(queue *q, int v)
{
  node *new_node = new node();
  new_node->value = v;

  if (q->rear)
  {
    q->rear->next = new_node;
    q->rear = new_node;
  }
  else
  {
    q->rear = new_node;
    q->front = new_node;
  }
  q->size++;
}

int is_queue_empty(queue *q)
{
  if (q->size)
  {
    return -1;
  }
}

int dequeue(queue *q)
{
  int value = q->front->value;
  q->front = q->front->next;
  q->size--;
  return value;
}

int main()
{
  queue Q = {NULL, NULL, 0};
  int op, v;
  while (true)
  {
    printf("Menu : ");
    scanf("%d", &op);
    if (op == 0)
    {
      scanf("%d", &v);
      enqueue(&Q, v);
    }
    else if (op == 1)
    {
      if (is_queue_empty(&Q) == 1)
        printf("Queue is already empty!!!\n");
      else
        printf("%d\n", dequeue(&Q));
    }
    else
    {
      printf("END CODE\n");
      break;
    }
  }
  return 0;
}