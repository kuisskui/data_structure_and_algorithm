#include <iostream>
using namespace std;

void flip_sort(int a[], int n, int *p)
{
    for (int i = 0; i < n-1;i++){
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            (*p)++;
            flip_sort(a, n, p);
        }
    }
}

int main()
{
    int n, x, a[1001], r;
    r = 0;
    int *p = &r;
    while (cin >> n)
    {
        int i = 0;
        while (i < n)
        {
            cin >> x;
            a[i] = x;
            i++;
        }
        flip_sort(a, n, p);
        cout << "Minimum exchange operations : ";
        cout << *p << endl;
        r = 0;
    }
}