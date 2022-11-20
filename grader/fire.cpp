#include <iostream>

using namespace std;

const int WIDTH = 20002;
const int FIRE = 11;
int field[WIDTH][WIDTH];

struct Node
{
    int row;
    int column;
    Node *next;
    Node(int row = 0, int column = 0, Node *next = 0)
        : row(row), column(column), next(next) {}
};

struct Queue
{
    Node *front;
    Node *rear;
    int size;
    Queue(Node *front = 0, Node *rear = 0, int size = 0)
        : front(front), rear(rear), size(size) {}
};

void enqueue(Queue *q, int row, int column)
{
    Node *new_node = new Node();
    new_node->row = row;
    new_node->column = column;

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
    q->size += 1;
}

int is_queue_empty(Queue *q)
{
    if (q->size)
    {
        return 0;
    }
    return 1;
}

Node dequeue(Queue *q)
{
    Node *front_node = q->front;
    if (!q->front->next)
    {
        q->front->next = 0;
        q->rear->next = 0;
    }
    else
    {
        q->front = q->front->next;
    }
    q->size -= 1;
    return *front_node;
}

void fire_field(Queue *q, Node node, int area)
{
    int next_row = node.row + 1;
    int next_column = node.column;
    if (next_row <= area)
    {
        enqueue(q, next_row, next_column);
    }
    next_row = node.row - 1;
    next_column = node.column;
    if (next_row >= 1)
    {
        enqueue(q, next_row, next_column);
    }
    next_row = node.row;
    next_column = node.column + 1;
    if (next_column <= area)
    {
        enqueue(q, next_row, next_column);
    }
    next_row = node.row;
    next_column = node.column - 1;
    if (next_column >= 1)
    {
        enqueue(q, next_row, next_column);
    }
}

bool check_field(int field[][WIDTH], int area)
{
    for (int i = 1; i <= area; i++)
    {
        for (int j = 1; j <= area; j++)
        {
            if (field[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void print_field(int field[][WIDTH], int area)
{
    for (int i = 1; i <= area; i++)
    {
        cout << '[';
        for (int j = 1; j <= area; j++)
        {
            cout << field[i][j] << ", ";
        }
        cout << ']' << endl;
    }
}

int main()
{
    Queue q;
    int area, fire, row, column, size, counter;
    counter = 0;
    cin >> area >> fire;
    for (int i = 0; i < fire; i++)
    {
        cin >> row >> column;
        enqueue(&q, row, column);
    }
    while (true)
    {
        size = q.size;
        for (int i = 0; i <= size; i++)
        {
            Node front_node = dequeue(&q);
            field[front_node.row][front_node.column] = 1;
            fire_field(&q, front_node, area);
        }
        print_field(field, area);
        cout << endl;
        if (check_field(field, area))
        {
            break;
        }
        counter += 1;
    }
    cout << counter;
}
