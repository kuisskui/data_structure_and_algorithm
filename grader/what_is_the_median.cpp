#include <iostream>
#include <algorithm>
using namespace std;

void store_array(int a[], int n, int i)
{
    a[i] = n;
    while (a[i] < a[i - 1] && i != 0)
    {
        swap(a[i], a[i - 1]);
        i--;
    }
}

void what_is_the_median(int a[], int i)
{
    int r, h;
    i++;
    h = i / 2;
    if (i % 2 == 0)
    {
        r = a[h];
    }
    else
    {
        r = (a[h] + a[h + 1]) / 2;
    }
    cout << r << endl;
}

int main()
{
    int i = 0;
    int n, a[100];
    a[0] = 0;
    while (cin >> n)
    {
        i++;
        store_array(a, n, i);
        what_is_the_median(a, i);
    }
}