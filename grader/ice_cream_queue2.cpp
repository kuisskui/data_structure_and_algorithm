#include <iostream>
using namespace std;

struct Customer
{
    int id;
    int flavor;
    Customer *next;

    Customer(int id = 0, int flavor = 0, Customer *next = 0)
        : id(id), flavor(flavor), next(next) {}
};

void append_list(Customer *header, Customer *new_customer)
{
    Customer *local_header = header;
    while (local_header->next->next)
    {
        local_header = local_header->next;
    }
    new_customer->next = local_header->next;
    local_header->next = new_customer;
}

int count_list(Customer *header){
    Customer *local_header = header;
    int count = 0;
    while (local_header->next->next){
        local_header = local_header->next;
        count++;
    }
    return count;
}

void print_list(Customer *header)
{
    Customer *local_header = header;
    while (local_header->next->next)
    {
        local_header = local_header->next;
        cout << "Customer's id : " << local_header->id << endl;
    }
}

Customer* delete_front(Customer *header)
{
    Customer *local_header = header;
    Customer *deleted_customer = new Customer();
    deleted_customer->next = local_header->next;
    local_header->next->next = local_header->next->next->next;
    return deleted_customer->next;
}

int main()
{
    int n_event;
    int event_type;
    int n_customer;
    int id;
    int flavor;
    int array_flavor_served[21] = {0};

    Customer *header = new Customer();
    Customer *tail = new Customer();
    header->next = tail;

    cin >> n_event;
    while (n_event--)
    {
        cin >> event_type;
        if (event_type == 1)
        {
            cin >> n_customer;
            while (n_customer--)
            {
                cin >> id;
                // cin >> flavor;
                Customer *new_customer = new Customer(id);
                append_list(header, new_customer);
            }
        }
        if (event_type == 2)
        {
            // Customer *deleted_customer = delete_front(header);
            // cout << deleted_customer->id << endl;
            Customer *deleted_customer = header->next;
            cout << deleted_customer->id << endl;
            header->next = header->next->next;
            array_flavor_served[deleted_customer->flavor] += 1;
        }
    }
    cout << count_list(header) << endl;
    // print_list(header);
    // for (int i = 1; i <= 20;i++){
    //     cout << array_flavor_served[i] << ' ';
    // }
}