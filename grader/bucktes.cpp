#include <iostream>
using namespace std;

void fill_water(int *p, int value, int *p_tank)
{
    *p += value;
    if (*p >= 1000)
    {
        *p = 0;
        *p_tank += 1000;
    }
}

int min_bucket_index(int b[])
{
    int min_index = 0;
    int min_water = 1000;
    int i = 0;
    int n = 5;
    while (i < n)
    {
        if (min_water > b[i])
        {
            min_water = b[i];
            min_index = i;
        }
        i++;
    }
    return min_index;
}

int main()
{
    int n, j;
    int target_bucket_index = 0;
    int tank = 0;
    int *p_tank = &tank;
    int b[5] = {0, 0, 0, 0, 0};
    cin >> n;
    int i = 0;
    while (i < n)
    {
        cin >> j;
        fill_water(&b[target_bucket_index], j, p_tank);
        target_bucket_index = min_bucket_index(b);
        i++;
    }
    cout << *p_tank << endl;
}