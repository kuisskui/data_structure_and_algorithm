#include <iostream>
using namespace std;

struct Card
{
    int value;
    Card *next;
    Card(int value = 0, Card *next = 0)
        : value(value), next(next) {}
};

void print_list(Card *header)
{
    Card *local_header = header;
    while (local_header->next->next)
    {
        local_header = local_header->next;
        cout << local_header->value << endl;
    }
}

int main()
{
    int n_sequence;
    int n_card;
    int sequence;
    int value;
    int my_sum;
    Card *header = new Card(111);
    Card *tail = new Card(999);
    header->next = tail;
    cin >> n_card >> n_sequence;

    Card *local_header = header;
    for (int i = 0; i < n_card; i++)
    {
        cin >> value;
        Card *new_card = new Card(value);
        new_card->next = local_header->next;
        local_header->next = new_card;
        local_header = local_header->next;
    }

    local_header = header;
    for (int i = 0; i < n_sequence; i++)
    {
        cin >> sequence;
        my_sum = 0;
        while (true)
        {
            
            if (local_header->next->next == 0){
                local_header = header;
            }
            my_sum += local_header->next->value;
            if (my_sum >= sequence)
            {
                // 
                local_header->next = local_header->next->next;
                break;
            }
            local_header = local_header->next;
        }
    }
    print_list(header);
}