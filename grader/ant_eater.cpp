#include <iostream>
using namespace std;

void update_total(int *total, int ants, bool *p_active)
{
    if (*p_active)
    {
        if (ants >= 1000)
        {
            *total += 1000;
            *p_active = false;
        }
        else
        {
            *total += ants;
        }
    }
    else
    {
        *p_active = true;
    }
}

int main()
{
    int total = 0;
    int *p_total = &total;
    bool active = true;
    bool *p_active = &active;
    int days, ants;
    cin >> days;
    while (days != 0)
    {
        cin >> ants;
        update_total(p_total, ants, p_active);
        days--;
    }
    cout << *p_total << endl;
    return 0;
}