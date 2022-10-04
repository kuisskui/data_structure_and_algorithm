#include <iostream>
using namespace std;

struct Player
{
    int point;
    Player *next;
    Player(int point = 0, Player *next = 0)
        : point(point), next(next) {}
};

void insert_player(Player *angel, Player *new_player)
{
    new_player->next = angel->next;
    angel->next = new_player;
}

void append_player(Player *header, Player *new_player)
{
    Player *local_header = header;
    while (local_header->next->next)
    {
        local_header = local_header->next;
    }
    new_player->next = local_header->next;
    local_header->next = new_player;
}

void print_list(Player *header){
    Player *local_header = header;
    while (local_header->next->next){
        local_header = local_header->next;
        cout << local_header->point << endl;
    }
}

int main()
{
    int n_player;
    int m_event;
    int event;
    int point;

    Player *header = new Player(999);
    Player *tail = new Player(999);
    header->next = tail;

    cin >> n_player >> m_event;

    Player *local_player = header;
    for (int i = 0; i < n_player; i++)
    {
        Player *new_player = new Player();
        new_player->next = local_player->next;
        local_player->next = new_player;
        // append_player(header, new_player);
    }
    Player *angel = header->next;

    while (m_event--){
        cin >> event;
        if(event==0){
            angel = header->next;
        }
        if(event==1){
            if (angel->next->next){
                angel = angel->next;
            }
            else{
                angel = header->next;
            }
        }
        if(event==2){
            Player *new_player = new Player();
            insert_player(angel, new_player);
        }
        if(event==3){
            cin >> point;
            angel->point += point;
        }   
    }
    print_list(header);
}