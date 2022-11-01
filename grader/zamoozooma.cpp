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
void enqueue_front(queue *q, int v)
{
    node *new_node = new node();
    new_node->value = v;

    if (q->front)
    {
        new_node->next = q->front;
        q->front = new_node;
    }
    else
    {
        q->rear = new_node;
        q->front = new_node;
    }
    q->size++;
}

void do_duty_for_enqueue_front(queue *q)
{
    node *local_header = q->front;
    int base_value = q->front->value;
    while (local_header->next)
    {
        local_header = local_header->next;
        if (local_header->value == base_value)
        {
            q->front = local_header->next;
            break;
        }
    }
}

int count_link_list(queue *q)
{
    node *local_head = q->front;
    int counter = 0;

    while (local_head->next)
    {
        counter++;
        local_head = local_head->next;
    }
    return counter;
}
void do_duty_for_enqueue(queue *q)
{
    node *sub_head = new node();
    sub_head->next = q->front;

    int base_value = q->rear->value;
    while (sub_head->next->next->next)
    {
        if (sub_head->next->value == base_value)
        {
            q->rear = sub_head;
            break;
        }
        sub_head = sub_head->next;
    }
}
int is_queue_empty(queue *q)
{
    if (q->size)
    {
        return -1;
    }
    return 1;
}
int dequeue(queue *q)
{
    int value = q->front->value;
    q->front = q->front->next;
    q->size--;
    return value;
}

void print_queue(queue *q)
{
    node *local_header = q->front;
    cout << "print link list" << endl;
    while (local_header->next)
    {
        cout << local_header->value << endl;
        local_header = local_header->next;
    }
    cout << local_header->value << endl;
}

int main()
{
    queue Q = {NULL, NULL, 0};
    int op, v;
    // while (true)
    // {
    //     printf("Menu : ");
    //     scanf("%d", &op);
    //     if (op == 0)
    //     {
    //         scanf("%d", &v);
    //         enqueue(&Q, v);
    //     }
    //     else if (op == 1)
    //     {
    //         scanf("%d", &v);
    //         enqueue_front(&Q, v);
    //     }
    //     else if (op == 2)
    //     {
    //         print_queue(&Q);
    //     }
    //     else if (op == 3)
    //     {
    //         if (is_queue_empty(&Q) == 1)
    //             printf("Queue is already empty!!!\n");
    //         else
    //             printf("%d\n", dequeue(&Q));
    //     }
    //     else
    //     {
    //         printf("END CODE\n");
    //         break;
    //     }
    // }

    int round, position, value;
    cin >> round;
    for (int i = 0; i < round; i++)
    {
        cin >> position >> value;
        if (position == 0)
        {
            enqueue_front(&Q, value);
            do_duty_for_enqueue_front(&Q);
        }
        else
        {
            enqueue(&Q, value);
            do_duty_for_enqueue(&Q);
        }
    }
    cout << count_link_list(&Q)+1 << endl;
    return 0;
}