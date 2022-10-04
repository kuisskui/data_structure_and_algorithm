#include <iostream>

using namespace std;

struct Ball
{
    int color;
    int index;
    Ball *next;

    Ball(int color = 0, int index = 0, Ball *next = 0)
        : color(color), index(index), next(next) {}
};

void print_list(Ball *header){
    Ball *local_header = header->next;
    while (local_header->next != 0)
    {
        cout << local_header->index << endl;
        local_header = local_header->next;
    }
    cout << local_header->index << endl;
}

void insert(Ball *header, int color, int index, int target)
{
    Ball *local_header = header;
    while (local_header->index != target)
    {
        local_header = local_header->next;
    }
    Ball *p = new Ball(color, index, local_header->next);
    local_header->next = p;
}

void append(Ball *header, int color, int index)
{
    Ball *local_header = header;
    while (local_header->next != 0)
    {
        local_header = local_header->next;
    }
    Ball *p = new Ball(color, index, 0);
    local_header->next = p;
}

int main()
{
    int balls;
    int target_balls;
    int color;
    int target;
    int total_balls;
    Ball *header = new Ball();

    cin >> balls;
    cin >> target_balls;

    total_balls = balls + target_balls;

    int index = 1;
    while (index <= balls)
    {
        cin >> color;
        append(header, color, index);
        // insert(header,x);
        index++;
    }
    while (index <= total_balls)
    {
        cin >> color >> target;
       
        insert(header, color, index, target);
        // insert(header,x);
        index++;
    }
    print_list(header);
}
