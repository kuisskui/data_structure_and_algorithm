#include <iostream>
using namespace std;

struct Cookie
{   
    int code;
    Cookie *next;

    Cookie(int code = 0, Cookie *next = 0)
        : code(code), next(next) {}
};

void insert_by_index(Cookie *header, Cookie *new_cookie, int index)
{
    Cookie *local_header = header;
    int i = 0;
    while (i < index && local_header->next)
    {
        local_header = local_header->next;
        i++;
    }
    new_cookie->next = local_header->next;
    local_header->next = new_cookie;
}

void delete_by_index(Cookie *header, int index)
{
    Cookie *local_header = header;
    int i = 1;
    while (i < index && local_header->next)
    {
        local_header = local_header->next;
        i++;
    }
    if (local_header->next){
        // local_header = local_header->next;
        if (local_header->next->next)
        {
            local_header->next = local_header->next->next;
        }
        else
        {
            local_header->next = 0;
        }
    }
}

void print_list(Cookie *header)
{
    Cookie *local_header = header->next;
    while (local_header->next)
    {
        cout << local_header->code << endl;
        local_header = local_header->next;
    }
}

int main()
{
    int n_event;
    int event_type;
    int code;
    int index;

    Cookie *sub_header = new Cookie();
    Cookie *header = new Cookie(0, sub_header);
    cin >> n_event;
    while (n_event--)
    {
        cin >> event_type;
        if (event_type == 1)
        {
            cin >> index >> code;
            Cookie *new_cookie = new Cookie(code = code);
            insert_by_index(header, new_cookie, index);
        }
        if (event_type == 2)
        {
            cin >> index;
            delete_by_index(header, index);
        }
    }
    print_list(header);
}