#include <iostream>
#include <stdio.h>
using namespace std;

typedef int valueType;
struct Node
{
    valueType value;
    Node *next;
    Node(valueType value = 0, Node *next = 0)
        : value(value), next(next) {}
};

struct Queue
{
    Node *front;
    Node *rear;
    int size;
    Queue(Node *front = 0, Node *rear = 0, int size = 0)
        : front(front), rear(rear), size(size) {}
};

void enqueue_front(Queue *q, int v)
{
    Node *new_node = new Node();
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

int is_queue_empty(Queue *q)
{
    if (q->size)
    {
        return 0;
    }
    return 1;
}

int find_queue(Queue *q, int index)
{
    Node *header = q->front;
    int value = header->value;
    for (int i = 0; i < index; i++)
    {
        header = header->next;
        value = header->value;
    }
    return value;
}

int dequeue(Queue *q)
{
    int value = q->front->value;
    if (!q->front->next)
    {
        q->front->next = 0;
        q->rear->next = 0;
    }
    else
    {
        q->front = q->front->next;
    }
    q->size--;
    return value;
}

void print_queue(Queue *q)
{
    int counter = 0;
    Node *header = q->front;
    cout << "index"
         << " : "
         << "value" << endl;
    while (header->next)
    {
        cout << counter << " : " << header->value << endl;
        header = header->next;
        counter++;
    }
    cout << counter << " : " << header->value << endl;
    cout << "size: " << q->size << endl;
    cout << "end queue" << endl;
}

bool is_front_most(Queue *q)
{
    Node *header = q->front;
    int value = header->value;

    while (header->next)
    {
        if (value < header->next->value)
        {
            return 0;
        }
        header = header->next;
    }
    if (value < header->value)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int n, n_items, item, counter, your_item_index;
    Queue q;
    cin >> n;
    while (n--)
    {
        q = Queue();
        cin >> n_items >> your_item_index;
        for (int i = 0; i < n_items; i++)
        {
            cin >> item;
            enqueue_front(&q, item);
        }

        counter = 0;
        while (true)
        {
            if (your_item_index <= 0)
            {
                if (is_front_most(&q))
                {
                    counter += 1;
                    n_items -= 1;
                    break;
                }
                else
                {
                    int value = dequeue(&q);
                    enqueue_front(&q, value);
                    your_item_index = n_items - 1;
                    continue;
                }
            }
            if (is_front_most(&q))
            {
                dequeue(&q);
                counter++;
                n_items -= 1;
                your_item_index -= 1;
            }
            else
            {
                int value = dequeue(&q);
                enqueue_front(&q, value);
                your_item_index -= 1;
            }
        }
        cout << counter << endl;
    }
}