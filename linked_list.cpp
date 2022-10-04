#include <iostream>

typedef struct node
{
    int value;
    struct node *next;
} node;

void print_linklist(node *p)
{
    int i = 0;
    while (p != NULL)
    {
        printf("(%d)-%d ", i, p->value);
        p = p->next;
        i++;
    }
    printf("\n");
}

node *add_front(node *p)
{
    int value;
    node *new_node = new node();

    scanf("%i", &value);
    new_node->value = value;
    if (p == 0)
    {
        p = new_node;
        return p;
    }
    new_node->next = p;
    return new_node;
}

node *add_back(node *p)
{
    int value;
    node *new_node = new node();
    node *local_header = p;
    scanf("%i", &value);
    if (p == 0)
    {
        p = new_node;
        p->value = value;
    }
    else
    {
        while (local_header->next)
        {
            local_header = local_header->next;
        }
        local_header->next = new_node;
        local_header = local_header->next;
        local_header->value = value;
    }
    return p;
}

int len_linklist(node *p)
{
    int count = 1;
    node *local_header = p;
    while (local_header->next)
    {
        local_header = local_header->next;
        count++;
    }
    return count;
}

node *delete_index(node *p)
{
    node *local_header = p;
    int index;
    scanf("%i", &index);
    for (int i = 1; i < index; i++)
    {
        local_header = local_header->next;
    }
    if (index == 0)
    {
        p = p->next;
    }
    else if (local_header->next->next)
    {
        local_header->next = local_header->next->next;
    }
    else
    {
        local_header->next = NULL;
    }
    return p;
}

node *delete_value(node *p)
{
    node *local_header = p;
    int index = 0;
    int value;
    scanf("%i", &value);
    while (true)
    {
        if (local_header->value == value)
        {
            return p->next;
        }
        while (local_header->next && local_header->next->value != value)
        {
            local_header = local_header->next;
        }
        if (local_header->next)
        {
            local_header->next = local_header->next->next;
        }
        else
        {
            break;
        }
    }
    return p;
}

int main()
{
    node *head = NULL;
    int op;
    while (true)
    {
        printf("Menu : ");
        scanf("%d", &op);
        if (op == 0)
            print_linklist(head);
        else if (op == 1)
            head = add_front(head);
        else if (op == 2)
            head = add_back(head);
        else if (op == 3)
            printf("len = %d\n", len_linklist(head));
        else if (op == 4)
            head = delete_index(head);
        else if (op == 5)
            head = delete_value(head);
        else
        {
            printf("END CODE\n");
            break;
        }
    }
    return 0;
}