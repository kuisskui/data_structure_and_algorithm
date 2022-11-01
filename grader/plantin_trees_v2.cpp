#include <iostream>
using namespace std;
int r[100] = {0};
int c[100] = {0};

struct Tree
{
    int index;
    int row;
    int column;
    Tree *next;
};

Tree* append_tree(Tree *header, int index, int row, int col)
{
    Tree *local_header = header;
    Tree *new_tree = new Tree();
    new_tree->index = index;
    new_tree->row = row;
    new_tree->column = col;
    if (!local_header)
    {
        header = new_tree;
    }
    else
    {
        while (local_header->next)
        {
            local_header = local_header->next;
        }
        local_header->next = new_tree;
        local_header = local_header->next;
    }
    return header;
}

void print_list(Tree *header)
{
    Tree *local_header = header;
    while (local_header->next)
    {
        cout << "Yo: " << local_header->index << endl;
        local_header = local_header->next;
    }
        cout << "Yo: " << local_header->index << endl;
}

int main()
{
    Tree *header = 0;
    int n_r, n_c, n;
    cin >> n_r >> n_c >> n;

    int input_r, input_c;
    for (int i = 1; i <= n; i++)
    {
        cin >> input_r >> input_c;
        header = append_tree(header, i, input_r, input_c);
        r[input_r] += 1;
        c[input_c] += 1;
    }
    // print_list(header);
    int max = 0;
    int index = 0;
    Tree *local_header = header;
    while (local_header->next)
    {
        int find = r[local_header->row] + c[local_header->column];
        if (find > max)
        {
            max = find;
            index = local_header->index;
        }
        local_header = local_header->next;
    }

    cout << index << ' ' << max - 1 << endl;
}